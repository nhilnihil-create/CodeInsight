#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 10;
int n, c, ps[N], va[N], cb[N], ucb[N], ans;
signed main() {
	scanf("%lld%lld", &n, &c);
	for (int i = 1; i <= n; ++i) scanf("%lld%lld", ps + i, va + i), va[i] += va[i - 1];
	for (int i = 1; i <= n; ++i) {
		cb[i] = max(cb[i - 1], va[i] - ps[i]);
		ans = max(ans, cb[i]);
	}
	for (int i = n; i; --i) {
		ucb[i] = max(ucb[i + 1], (va[n] - va[i - 1]) - (c - ps[i]));
		ans = max(ans, ucb[i]);
	}
	for (int i = 1; i <= n; ++i) {
		ans = max(ans, va[i] - ps[i] * 2 + ucb[i + 1]);
		ans = max(ans, (va[n] - va[i]) - (c - ps[i + 1]) * 2 + cb[i]);
	}
	printf("%lld\n", ans);
	return 0;
}