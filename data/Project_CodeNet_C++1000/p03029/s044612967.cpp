#include <stdio.h>
int main()
{
	int apple,piece,total_pieces;
	
	scanf("%i %i",&apple,&piece);
	
	total_pieces = piece + (apple*3);
	
	printf("%i",total_pieces/2);
	
	return 0;
}