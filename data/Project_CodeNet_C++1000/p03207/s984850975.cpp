#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int p[10];
	for (int i = 0; i < N; i++) {
		scanf("%d", &p[i]);
	}
	sort(p, p + N);
	int ans = 0;
	for (int i = 0; i < N - 1; i++) {
		ans += p[i];
	}
	ans += p[N - 1] / 2;
	printf("%d\n", ans);
	return 0;
}
