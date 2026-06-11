#include <bits/stdc++.h>

using namespace std;


long long ans = 0x3f3f3f3f3f3f3f3fLL;
long long sum[300005], b[105];
int a[300005];
int n;

long long gao(int x, int y, int z) {
	b[1] = sum[x];
	b[2] = sum[y] - sum[x];
	b[3] = sum[z] - sum[y];
	b[4] = sum[n] - sum[z];

	sort(b + 1, b + 1 + 4);
	
	return b[4] - b[1];
}
int main( ) {
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	int curx = 1, cury = 3;
	for (int i = 3; i <= n - 1; i ++) {
		while (curx + 1 <= i - 2 && sum[curx + 1] * 2 <= sum[i - 1]) ++ curx;
		while (cury + 1 < n && (sum[cury + 1] - sum[i - 1]) * 2 <= sum[n] - sum[i - 1]) ++ cury;
		ans = min(ans, gao(curx, i - 1, cury));
		if (curx + 1 <= i - 2 && cury + 1 < n) {
			ans = min(ans, gao(curx + 1, i - 1, cury + 1));
		}
		if (curx + 1 <= i - 2) ans = min(ans, gao(curx + 1, i - 1, cury));
		if (cury + 1 < n) ans = min(ans, gao(curx, i - 1, cury + 1));
	}
	printf("%lld\n", ans);
	return 0;
}
