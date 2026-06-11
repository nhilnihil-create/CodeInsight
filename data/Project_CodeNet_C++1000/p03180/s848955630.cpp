#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define x first
#define y second

#ifdef LOCAL
#include "/Users/swad/Desktop/CP/debug.h"
#endif

// const int N = int(1e5) + 10;
// const int MOD = int(1e9) + 7;

int n;
vector<ll> dp, f;
vector<vector<int>> a;

int main() {
	#ifdef LOCAL
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

	scanf("%d", &n);

	a.resize(n, vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	f.resize(1 << n, 0);
	for (int mask = 1; mask < 1 << n; mask++) {
		f[mask] = f[mask & (mask - 1)];
		for (int _mask = mask; _mask; _mask &= (_mask - 1)) {
			f[mask] += a[__builtin_ctz(mask)][__builtin_ctz(_mask)];
		}
	}

	dp.resize(1 << n, 0);
	for (int mask = 1; mask < 1 << n; mask++) {
		for (int _mask = mask; _mask; _mask = (_mask - 1) & mask) {
			dp[mask] = max(dp[mask], f[_mask] + dp[mask ^ _mask]);
		}
	}

	printf("%lld\n", dp.back());

	return 0;
}