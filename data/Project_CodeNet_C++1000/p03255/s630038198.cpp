#include <bits/stdc++.h>

#define For(i, j, k) for (int i = j; i <= k; i++)

using namespace std;

const int N = 2e5 + 10;

typedef long long LL;

int n, X;
LL sum[N];

int main() {

	scanf("%d%d", &n, &X);
	For(i, 1, n) scanf("%lld", &sum[i]), sum[i] += sum[i - 1];

	LL ans = 1ll << 60;
	For(i, 1, n) {
		LL cur = 1ll * (i + n) * X;
		for (int j = n, c = 0; j > 0; j -= i, ++c) {
			LL w = (!c ? 5 : 2 * c + 3) * (sum[j] - sum[max(j - i, 0)]);
			cur += w;
			if (cur >= ans) break;
		}
		ans = min(ans, cur);
	}
	printf("%lld\n", ans);

	return 0;
}