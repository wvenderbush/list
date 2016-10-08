#include <stdio.h>
#include <stdlib.h>

//Winston Venderbush
//Linked Lists
//10/8/16

struct node { int i; struct node *next; };

void print_list(struct node * start){
	struct node *curr = start;
	printf("[");
	while (curr != NULL){
		printf("%i", (*curr).i);
		curr = (*curr).next;
		if (curr != NULL){
			printf(", ");
		}
	}
	printf("]\n");
}

struct node * insert_front(int add, struct node * start){
	struct node *p_n0 = (struct node *)malloc(sizeof(struct node));
	(*p_n0).i = add;
	(*p_n0).next = start;
	return p_n0;
}

struct node * free_list(struct node * start){
	struct node *curr = start;
	struct node *next = (*curr).next;
	while (curr != NULL){
		next = (*curr).next;
		free(curr);
		curr = next;
	}
	curr = NULL;
	start = NULL;
	return start;
}

int main(){

	struct node *p_n1 = (struct node *)malloc(sizeof(struct node));
	struct node *p_n2 = (struct node *)malloc(sizeof(struct node));
	struct node *p_n3 = (struct node *)malloc(sizeof(struct node));

	struct node *list = p_n1;

	(*p_n1).i = 1;
	(*p_n1).next = p_n2;
	(*p_n2).i = 2;
	(*p_n2).next = p_n3;
	(*p_n3).i = 3;
	(*p_n3).next = NULL;


	printf("printed list: ");
	print_list(list);

	printf("new node added to front: ");
	list = insert_front(0, list);
	print_list(list);

	printf("adding another: ");
	list = insert_front(7, list);
	print_list(list);

	printf("freeing the list... list nodes freed!\n");
	list = free_list(list);
}

