#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int V[20], C[20];
	for (int i = 0; i < N; i++) {
		scanf("%d", &V[i]);
	}
	for (int i = 0; i < N; i++) {
		scanf("%d", &C[i]);
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (V[i] > C[i]) ans += V[i] - C[i];
	}
	printf("%d\n", ans);
	return 0;
}
