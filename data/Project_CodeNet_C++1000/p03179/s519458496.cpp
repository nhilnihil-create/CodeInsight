#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
const int maxn = 3010;
ll dp[maxn][maxn];

int main() {
	ios_base::sync_with_stdio(false);

	int n;
	string s;
	cin >> n >> s;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		ll pref[i];
		pref[0] = 0;
		for (int j = 1; j < i; j++) {
			pref[j] = (pref[j - 1] + dp[i - 1][j]) % mod;
		}
		for (int j = 1; j <= i; j++) {
			int l, r;
			if (s[i - 2] == '<') {
				l = 1, r = j - 1;
			} else {
				l = j, r = i - 1;
			}
			if (l <= r) {
				dp[i][j] = (pref[r] - pref[l - 1] + mod) % mod;
			}
		}
	}
	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + dp[n][i]) % mod;
	}
	cout << ans;

	return 0;
}