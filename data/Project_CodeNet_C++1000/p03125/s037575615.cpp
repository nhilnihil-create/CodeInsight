#include<stdio.h>
int main(){
	int A,B;
	scanf("%d %d", &A,&B);
	printf("%d\n", (B%A == 0) ? A+B : B-A);
	return 0;
}