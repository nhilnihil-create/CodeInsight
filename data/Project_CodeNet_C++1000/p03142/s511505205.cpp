#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
int n, m, deg[N], p[N];
vector <int> ad[N];

main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n + m - 1; ++i) {
		int u, v;
		cin >> u >> v;
		ad[u].push_back(v);
		deg[v]++;
	}
	queue <int> q;
	for(int i = 1; i <= n; ++i) if(!deg[i]) q.push(i);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto &v : ad[u]) {
			deg[v]--;
			if(!deg[v]) {
				p[v] = u;
				q.push(v);
			}
		}
	}
	for(int i = 1; i <= n; ++i) cout << p[i] << '\n';
}