#include <stdio.h>
int main(void)
{
	int one,A,B;
	scanf("%d", &one);
	if (one==1){
			printf("Hello World");
	}
	if (one==2){
		scanf("%d", &A);
		scanf("%d", &B);
		printf("%d",A+B);
	}
	return 0;
}