#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int board[9]; 
void printboard()
{
	printf(" %d | %d | %d\n %d | %d | %d\n %d | %d | %d\n", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8]);
}
void getchoice(int player)
{
	 int c; 
	printf("Player %d enter a number 1-9 : ", player);
	scanf("%d", &c);
	
	if (c > 9 || c < 1)
	{
		printf(" Invalid move, lose your turn ");
	}
	else if (board[c - 1] != 0)
	{
		printf(" Invalid move, lose your turn\n");
	}
	else 
	{
		board[c - 1] = player;
	}

}
void checkboard()
{
	int starts[8] = { 0,3,6,0,1,2,0,2 };
	int increments[8] = { 1,1,1,3,3,3,4,2 };
	for (int path = 0 ; path != 8 ; path++)
	{
		int counts[3] = { 0,0,0 };
		for (int p = starts[path]; p != starts[path] + increments[path] * 3; p += increments[path])
		{
			int value = board[p];
			counts[value] = counts[value] + 1;
		}

		if (counts[1] == 3)
		{
			printf("Player 1 wins");
			exit(0);
		}
		if (counts[2] == 3)
		{
			printf("Player 2 wins");
			exit(0);
		}
	}
}
void do_ai(int p)
{
	int moves[9] = { 0,0,0,0,0,0,0,0,0 };
	int nmoves = 0;
	for (int i = 0; i <= 8; i++)
	{
		if (board[i] == 0)
			moves[nmoves++] = i;
	}
	int choice = moves[rand() % nmoves];
	board[choice] = p;
	printf(" Computer played %d\n", choice);
}
int main()
{
	printboard();
	for(;;)
	{ 
		getchoice(1);
		printboard();
		checkboard();
		do_ai(2);
		printboard();
		checkboard();
	}
	
}
