#include <stdio.h>

int main(){
	int Apple, Pieces;
	scanf("%d %d", &Apple, &Pieces);
	
	int ApplePie = 0;
	Apple *= 3;
	Pieces += Apple;
	for(int i = 0; Pieces > 1; i++){
		Pieces -= 2;
		ApplePie++;
	}
	
	printf("%d", ApplePie);
	
	return 0;
}