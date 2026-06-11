#include <stdio.h>

int main(){
	int apples, applePiece;
	scanf("%d %d", &apples, &applePiece);
	int cutApple = apples*3;
	int appleAll = cutApple + applePiece; 
	printf("%d", appleAll/2);
	
	
	
	return 0;
}