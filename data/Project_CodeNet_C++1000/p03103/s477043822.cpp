#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

int main(void) {
	int N, M;
	scanf("%d %d", &N, &M);
	pair<int, int> shops[100100];
	for (int i = 0; i < N; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		shops[i] = make_pair(A, B);
	}
	sort(shops, shops + N);
	long long ans = 0;
	int i = 0;
	while (M > 0) {
		// cout << shops[i].first << "  " << shops[i].second << "\n";
		ans += (long long)shops[i].first * min(shops[i].second, M);
		M -= shops[i].second;
		i++;
	}
	printf("%lld\n", ans);
	return 0;
}
