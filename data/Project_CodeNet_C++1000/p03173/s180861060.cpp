#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using li = __int128;
using uli = unsigned __int128;

#define fi first
#define se second

template <typename T> void s_min(T& a, T b) {
	if (a > b) a = b;
}

template <typename T> void s_max(T& a, T b) {
	if (a < b) a = b;
}

const int MAXN = 410;
const ll INF = 1e18;
int N, a[MAXN];
ll dp[MAXN][MAXN], pref[MAXN];

ll rec(int l, int r) {
	if (l == r) return 0;
	if (dp[l][r] != -1) return dp[l][r];
	dp[l][r] = INF;
	for (int i = l; i < r; i++) {
		s_min(dp[l][r], rec(l, i) + rec(i + 1, r));
	}
	dp[l][r] = dp[l][r] + pref[r] - pref[l - 1];
	return dp[l][r];
}

int main() {
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		pref[i] = pref[i - 1] + a[i];
	}
	memset(dp, -1, sizeof(dp));
	ll ans = rec(1, N);
	cout << ans;

	return 0;
}