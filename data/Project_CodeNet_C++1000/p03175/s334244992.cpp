#include "bits/stdc++.h"
using namespace std;
#define Fast_IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
const int m = 1e9 + 7;
vector<vector<int>> adj;
vector<vector<int>> dp;
int dfs(int cur, int par, int col) {
	if (~dp[cur][col])
		return dp[cur][col];
	int ans = 1;
	if (col == 1) {
		//prev black
		for (auto i : adj[cur]) {
			if (i != par) {
				//paint cur white
				ans *= dfs(i, cur, 0);
				ans %= m;
			}
		}
	}
	else {
		//prev white
		for (auto i : adj[cur]) {
			if (i != par) {
				ans *= dfs(i, cur, 1) + dfs(i, cur, 0);
				ans %= m;
			}
		}
	}
	return dp[cur][col] = ans;
}


int32_t main() {
	Fast_IO
	int n; cin >> n;
	adj = vector<vector<int>>(n + 1);
	dp = vector<vector<int>>(n + 1, vector<int>(2, -1));
	for (int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cout << (dfs(1, -1, 0) + dfs(1, -1, 1)) % m;
}