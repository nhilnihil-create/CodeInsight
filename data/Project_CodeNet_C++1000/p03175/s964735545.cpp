#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
int n;
vector<vector<int>> adj;
vector<vector<ll>> dp;

ll solve(int cur, int prev, int col) {
	if (dp[cur][col] != -1)
		return dp[cur][col];
	ll tot = 0, w = 1;
	if (col == 0) {
		for (auto it : adj[cur]) {
			if (it != prev) {
				w = (w * solve(it, cur, 1)) % mod;
			}
		}
		tot += w;
	}
	w = 1;
	for (auto it : adj[cur]) {
		if (it != prev) {
			w = (w * solve(it, cur, 0)) % mod;
		}
	}
	tot = (tot + w) % mod;
	return dp[cur][col] = tot;
}

int main() {
	ios_base::sync_with_stdio(false);

	cin >> n;
	adj.resize(n);
	dp.resize(n);
	for (int i = 0; i < n; i++) {
		dp[i].resize(2, -1);
	}
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	ll answer = solve(0, -1, 0);
	cout << answer;

	return 0;
}