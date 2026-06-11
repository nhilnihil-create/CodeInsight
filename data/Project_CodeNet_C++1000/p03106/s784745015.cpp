#include<iostream>
#include<stdio.h>
using namespace std;

int main(void) {
	int A, B, K;
	scanf("%d %d %d", &A, &B, &K);
	int num = 0;
	for (int i = 100; i > 0; i--) {
		if (A % i == 0 && B % i == 0) {
			num++;
		}
		if (num == K) {
			printf("%d\n", i);
			return 0;
		}

	}
	return 0;
}
