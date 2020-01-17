// linkedlist.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

struct Node {
	int data;
	Node *next;
};

Node* addNode(Node*, int);
void display(Node*);
Node* deleteNode(Node*, int);
Node* reverselinkedlist(Node*);
void reversedisplay(Node*);
void reverserecursion(Node*);

Node *headglobal;

int main()
{
	Node *head = NULL;	
	head = addNode(head, 3);
	head = addNode(head, 5);
	head = addNode(head, 8);
	head = addNode(head, 10);

	cout << "Initial list: ";
	display(head);

	head = deleteNode(head, 5);
	cout << "\nNew list without 5 : ";
	display(head);

	head = addNode(head, 12);
	cout << "\nAdded 12 in the list: ";
	display(head);

	cout << "\nReverse of this linked list : ";
	head = reverselinkedlist(head);
	display(head);
		
	cout << "\nReverse Linked list using recursion:";
	headglobal = head;
	reverserecursion(headglobal);
	head = headglobal;
	display(head);

	cout << "\nReverse display: ";
	reversedisplay(head);



	getchar();
	return 0;
}

 void reverserecursion(Node* current) {
	if (current->next == NULL) {
		headglobal = current;
		return;
	}
	reverserecursion(current->next);
	Node *prev = current->next;
	prev->next = current;
	current->next = NULL;

}

void reversedisplay(Node* head) {
	if (head == NULL) {
		return;
	}
	reversedisplay(head->next);
	cout << head->data << ' ';
}


Node* reverselinkedlist(Node* head){
	Node*current = head;
	Node*prev = NULL;
	Node*nextnode = head->next;
	
	if (head == NULL) {
		cout << "\nEmply List";
	}

	while (current->next != NULL) {
		current->next = prev;
		prev = current;
		current = nextnode;
		nextnode = nextnode->next;
	}
	current->next = prev;
	head = current;
	
	return head;

}


Node* deleteNode(Node *head, int num) {
	Node *current, *prev;

	if (head == NULL) {
		cout << "\nNo data in the list";
		return head;
	}
	current = head;
	if (current->data == num) {
		head = current->next;
		delete current;
		return head;
	}
	current = head->next;
	prev = head;
	while (current != NULL) {
		if (current->data == num && current->next == NULL)
		{
			prev->next = NULL;
			delete current;
			return head;
		}
		else if(current->data == num)
		{
			prev->next = current->next;
			delete current;
			return head;
		}
		prev = current;
		current = current->next;
		
	}
}

Node* addNode(Node *head, int num) {
	Node *newNode = new Node; 
	newNode->data = num;
	newNode->next = NULL;
	if (head != NULL)
		newNode->next = head;
	head = newNode;
	return head;
}
void display(Node *head) {
	if (head == NULL)
	{
		cout << "List is empty!";
		return;
	}
	while (head != NULL)
	{
		cout << head->data << ' ';
		head = head->next;
	}
	return;
}
