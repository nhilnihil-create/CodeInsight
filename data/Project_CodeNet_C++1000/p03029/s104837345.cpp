#include <stdio.h>
int main(){
	
	int A;
	int F;
	scanf("%d%d", &A, &F);
	
	F = (F + 3 * A)/2;
	printf("%d", F);
	
	return 0;
}