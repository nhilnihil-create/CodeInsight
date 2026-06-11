#include <bits/stdc++.h>
using namespace std;
const int MAXn = 1e5 + 10;
typedef pair<int, int> pii;
vector<pii> g[MAXn];
long long n, m, dis[MAXn];
bool flag[MAXn];

void dfs(int v,  long long dist) {
	flag[v] = true;
	dis[v] = dist;
	for (pii u : g[v]) {
		if (flag[u.first])
			continue;
		dfs(u.first, dist + u.second);
	}
}

int  main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		g[u].push_back(pii(v, d));
		g[v].push_back(pii(u, -d));
	}
	for (int i = 1; i <= n; i++) {
		if (!flag[i]) {
			dfs(i, 0);
		}
	}
	for (int i = 1; i <= n; i++)
		for (pii u : g[i])
			if (dis[i] + u.second != dis[u.first])
				return cout << "No",0;
	cout << "Yes";
}
