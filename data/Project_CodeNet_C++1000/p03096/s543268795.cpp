#pragma GCC optimize("Ofast", "unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

const ll mod = 1000000007LL;

int main() {
	int N; cin >> N;
	vector<int> c;
	while (N--) {
		int ci; cin >> ci;
		if (c.size() == 0 || c[c.size() - 1] != ci)
			c.push_back(ci);
	}
	N = c.size();
	vector<ll> dp(N + 1, 0);
	map<int, ll> color_cnt;
	dp[0] = 1; color_cnt[c[0]] = 1;
	for (int i = 1; i <= N; ++i) {
		int ci = c[i - 1];
		dp[i] = color_cnt[ci];
		if (i < N) {
			int nx_c = c[i];
			color_cnt[nx_c] = (color_cnt[nx_c] + dp[i]) % mod;
		}
	}
	cout << dp[N] << endl;
	return 0;
}