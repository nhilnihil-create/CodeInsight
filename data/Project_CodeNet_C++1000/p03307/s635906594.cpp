#include <stdio.h>



int main()
{
	
	int A = 2;
	int i, N;
	
	scanf("%d", &N);
	
	if(N % 2 == 0){
		printf("%d", N);
	}
	else {
		printf("%d", N * 2);
	}

	return 0;
}