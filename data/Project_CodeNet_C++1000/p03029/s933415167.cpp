#include <stdio.h>

int main() 
{
	int A, P, AP;
	
	scanf("%d %d", &A, &P);
	
	A = A*3;
	P = P+A;
	AP = P/2;
	
	printf("%d", AP);
	
	
	return 0;
}