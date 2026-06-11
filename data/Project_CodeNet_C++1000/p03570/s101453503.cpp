#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9;
int s[200010];
int dp[200010];
int hsh[1 << 26];
int main() {
	string _s; cin >> _s;
	int n = _s.size();
	for(int i = 1; i <= n; ++i) {
		s[i] = s[i - 1] ^ (1 << (_s[i - 1] - 'a'));
		dp[i] = INF;
	}
	for(int i = 0; i < (1 << 26); ++i) {
		hsh[i] = INF;
	}
	hsh[0] = 0;
	for(int i = 1; i <= n; ++i) {
		dp[i] = min(dp[i], hsh[s[i]] + 1);
		hsh[s[i]] = min(hsh[s[i]], dp[i]);
		for(int j = 0; j < 26; ++j) {
			int pre = s[i] ^ (1 << j);
			dp[i] = min(dp[i], hsh[pre] + 1);
			hsh[s[i]] = min(hsh[s[i]], dp[i]);
		}
	}
	cout << dp[n] << '\n';
	return 0;
}