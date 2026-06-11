#include<stdio.h>
int main(void)
{
	int N, K;

	scanf("%d%d", &N, &K);

	int A;
	A = N + 1;

	if (N % 2 == 0) {
		if (N / 2 >= K) {
			printf("YES");
		}
		else
			printf("NO");
	}
	else {
		if (A / 2 >= K) {
			printf("YES");
		}
		else
			printf("NO");
	}







	return 0;
}