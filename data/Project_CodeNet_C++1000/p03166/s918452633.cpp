#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	vector<bool> vis(n);
	vector<int> dp(n);
	function<void (int u)> dfs = [&](int u) {
		vis[u] = true;
		for (int &x : graph[u]) {
			if (!vis[x]) {
				dfs(x);
				
				
			}
			dp[u] = max(dp[u], dp[x] + 1);
		}
		return;
	};
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		a--, --b;
		graph[a].push_back(b);
	}
	for (int i = 0; i < n; ++i) {
		if (!vis[i])
			dfs(i);
	}
	cout << *max_element(dp.begin(), dp.end());
	return 0;
}