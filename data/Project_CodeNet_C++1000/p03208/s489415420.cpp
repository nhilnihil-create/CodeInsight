#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	int h[100100];
	for (int i = 0; i < N; i++) {
		scanf("%d", &h[i]);
	}
	sort(h, h + N);
	int ans = 2000000000;
	for (int i = K - 1; i < N; i++) {
		ans = min(ans, h[i] - h[i - K + 1]);
	}
	printf("%d\n", ans);

	return 0;
}
