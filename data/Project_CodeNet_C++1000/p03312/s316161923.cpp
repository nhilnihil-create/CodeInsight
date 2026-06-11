#include <bits/stdc++.h>
using namespace std;

const long long inf = 1000000000000000013;
const int maxn = 200005;

int n;
int a[maxn];
long long ans = inf;
long long pref[maxn];

long long f (int pos, int i, int j) {
	if (!pos || pos >= i || j <= i || j == n)
		return inf;
	long long x1 = pref[pos], x2 = pref[i] - pref[pos], x3 = pref[j] - pref[i], x4 = pref[n] - pref[j];
	return max(max(x1, x2), max(x3, x4)) - min(min(x1, x2), min(x3, x4));
}

signed main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		pref[i] = pref[i - 1] + a[i];
	}
	for (int i = 2; i <= n - 2; ++i) {
		auto l = upper_bound(pref, pref + n + 1, pref[i] / 2) - pref;
		auto r = upper_bound(pref, pref + n + 1, pref[i] + (pref[n] - pref[i]) / 2) - pref;
		for (int pos = l - 1; pos <= l; ++pos) {
			for (int j = r - 1; j <= r; ++j)
				ans = min(ans, f(pos, i, j));
		}
	}
	printf("%lld\n", ans);
}
