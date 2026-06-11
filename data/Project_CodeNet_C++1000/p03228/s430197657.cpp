#include<stdio.h>
int main()
{
	long long A, B;
	int K;
	scanf("%lld%lld%d", &A, &B, &K);
	for (int i = 0; i < K; i++) {
		if (i % 2 == 0) {
			if (A % 2 == 0) {
				A /= 2;
				B += A;
			}
			else {
				A -= 1;
				A /= 2;
				B += A;
			}
		}
		else {
			if (B % 2 == 0) {
				B /= 2;
				A += B;
			}
			else {
				B -= 1;
				B /= 2;
				A += B;
			}
		}
	}
	printf("%lld %lld", A, B);
}