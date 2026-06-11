#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<vector<int>> g(n);
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		u--; v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	vector<int> d(n, -1);
	d[0] = 0;
	bool ok = false;
	function<void(int)> dfs = [&](int u) {
		for (auto v : g[u]) {
			if (d[v] != -1) {
				if (d[v] == d[u]) {
					ok = true;
				}
			} else {
				d[v] = 1 - d[u];
				dfs(v);
			}
		}
	};
	dfs(0);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += d[i];
	}
	long long tot;
	if (ok) {
		tot = (long long)n * (n - 1) / 2;
	} else {
		tot = (long long)cnt * (n - cnt);
	}
	cout << tot - m << endl;
	return 0;
}
