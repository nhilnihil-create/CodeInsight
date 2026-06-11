#include <stdio.h>

/*
Apples = 3 pieces of apple
1 apple pie = 3 pieces of apple
*/
int main (){
	int apples, pieces1 = 3, pieces2;
	int applePie;
	
	scanf ("%d %d", &apples, &pieces2);
	
	
	pieces1 = apples*3;
	applePie = (pieces1 + pieces2) / 2;
	
	printf ("%d",applePie);
	return 0;
}