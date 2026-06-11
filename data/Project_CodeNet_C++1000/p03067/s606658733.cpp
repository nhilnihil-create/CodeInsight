#include<stdio.h>
int main(void)
{
	int A,B,C;

	scanf("%d%d%d", &A, &B, &C);

	if (A < B && A < C) {
		if (B < C) {
			printf("No");
		}
		else
			printf("Yes");
	}
	else if (B < A && B < C) {
		if (A < C) {
			printf("No");
		}
		else
			printf("Yes");
	}

	else
		printf("No");





	return 0;
}