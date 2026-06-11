#include<iostream>
#include<stdio.h>
using namespace std;

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	int menu[30] = {0};
	for (int i = 0; i < N; i++) {
		int K;
		scanf("%d", &K);
		for (int i = 0; i < K; i++) {
			int A;
			scanf("%d", &A);
			menu[A - 1]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < M; i++) {
		if (menu[i] == N) ans++;
	}
	printf("%d\n", ans);

	return 0;
}
