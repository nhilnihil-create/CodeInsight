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

const int MAXN = 110, MAXK = 1e5 + 5, mod = 1e9 + 7;
int N, K, a[MAXN];
ll dp[MAXN][MAXK];

int main() {
	ios_base::sync_with_stdio(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> a[i];
	dp[0][0] = 1;
	for (int i = 1; i <= N; i++) {
		vector<ll> pref(K + 1);
		pref[0] = dp[i - 1][0];
		for (int j = 1; j <= K; j++) {
			pref[j] = (pref[j - 1] + dp[i - 1][j]) % mod;
		}
		for (int j = 0; j <= K; j++) {
			dp[i][j] = pref[j];
			int factor = j - a[i] - 1;
			if (factor >= 0) dp[i][j] = (dp[i][j] - pref[factor] + mod) % mod;
		}
	}
	cout << dp[N][K];

	return 0;
}