#include <stdio.h>
int main(void)
{
	int A, B, C;
	scanf("%d", &A); scanf("%d", &B); scanf("%d", &C);

	if (A == B && B == C)
		printf("Yes");
	else
		printf("No");

	return 0;

}