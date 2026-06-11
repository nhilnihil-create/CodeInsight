#include<stdio.h>
using namespace std;

int main(void)
{
	int A, B, K;
	int D;
	scanf("%d%d%d", &A, &B, &K);
	for (int i = 0; i < K; i++) {
		if (i % 2 == 0) {
			if (A % 2 == 1)
				A = A - 1;
			A = A / 2;
			B = B + A;
		}
		else {
			if (B % 2 == 1)
				B = B - 1;
			B = B / 2;
			A = A + B;
		}
	}

	printf("%d %d", A, B);

	return 0;
}