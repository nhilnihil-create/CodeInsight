#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX = (int) 1e5 + 5;

vector<int> g[MAX];
vector<int> dp(MAX);

void dfs(int u) {
	if (dp[u] != -1) {
		return;
	} else {
		dp[u] = 0;
		for (int v : g[u]) {
			dfs(v);	
			dp[u] = max(dp[u], dp[v] + 1);
		}
		return;
	}
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
	}
	dp.assign(n + 1, -1);
	for (int i = 0; i < n; i++) {
		dfs(i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << '\n';
  return 0;
}

