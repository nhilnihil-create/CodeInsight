#include<iostream>
#include<stdio.h>
using namespace std;

int main(void) {
	int N, M, C;
	scanf("%d %d %d", &N, &M, &C);
	int B[20];
	int A[20];
	for (int i = 0; i < M; i++) {
		scanf("%d", &B[i]);
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int val = 0;
		for (int j = 0; j < M; j++) {
			scanf("%d", &A[j]);
			val += A[j] * B[j];
		}
		val += C;
		if (val > 0) ans++;
	}

	printf("%d\n", ans);
	return 0;
}
