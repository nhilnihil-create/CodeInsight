#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(void) {
	int N, K;
	scanf("%d %d", &N, &K);
	int ans = 1;
	for (int i = 0; i < N; i++) {
		if (ans < K) ans *= 2;
		else ans += K;
	}
	printf("%d\n", ans);
	return 0;
}
