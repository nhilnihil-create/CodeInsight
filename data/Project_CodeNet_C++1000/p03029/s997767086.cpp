#include <stdio.h>

int main () {
	int Apple, Piece, Pies;
	scanf("%d", &Apple);
	scanf("%d", &Piece);
	
	Pies = ((Apple*3) + Piece)/2;
	printf("%d", Pies);
	return 0;
}