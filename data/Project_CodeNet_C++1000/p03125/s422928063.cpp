#include <stdio.h>

int main(){
	int A, B;
	scanf("%d %d", &A, &B);
	
	B%A==0?printf("%d", A+B):printf("%d", B-A);
	

	return 0;
}
