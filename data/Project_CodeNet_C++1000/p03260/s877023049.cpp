#include <stdio.h>

int main()
{
	
	int A, B;
	
	scanf("%d %d", &A, &B);
	
	if ((A*B*1)%2!=0 || (A*B*2)%2!=0 || (A*B*3)%2!=0){
		printf("Yes");
	}
	else{
		printf("No");
	}
	
	
	
	
	
	
	return 0;
}