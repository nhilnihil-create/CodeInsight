#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int, int>>> g(n);
	for (int i = 0; i < m; i++) {
		int l, r, d;
		cin >> l >> r >> d;
		l--; r--;
		g[l].emplace_back(r, d);
		g[r].emplace_back(l, -d);
	}
	vector<long long> dist(n, LLONG_MAX);
	bool ok = true;
	for (int i = 0; i < n; i++) {
		if (dist[i] != LLONG_MAX) continue;
		queue<int> que;
		que.push(i);
		dist[i] = 0;
		while ((int) que.size()) {
			int cur = que.front();
			que.pop();
			for (auto &nbr : g[cur]) {
				if (dist[nbr.first] != LLONG_MAX) {
					if (dist[nbr.first] != dist[cur] + nbr.second) ok = false;
				} else {
					dist[nbr.first] = dist[cur] + nbr.second;
					que.push(nbr.first);
				}
			}
		}
	}
	cout << (ok ? "Yes" : "No") << endl;
	return 0;
}