#include <stdio.h>

int main(){
	
	int apple;
	int pieces;
	
	scanf("%d %d", &apple, &pieces);
	
	int total = (apple * 3) + pieces;
	int pies = total / 2;
	
	
	printf("%d", pies);

return 0;
}