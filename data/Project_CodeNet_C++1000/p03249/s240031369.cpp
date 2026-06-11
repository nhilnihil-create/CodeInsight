#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> g[100005];
long long d[100005];
int rd[100005];
int sz[100005];
map<long long,int> mp;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> d[i];
		mp[d[i]] = i;
		sz[i] = 1;
	}
	for (int it = 1; it < n; ++it) {
		int u = mp.rbegin()->second;
		long long need = d[u] - (n - sz[u]) + sz[u];
		if (mp.find(need) == mp.end() || mp[need] == u) {
			return cout << -1 << '\n',0;
		} 
		int v = mp[need];
		g[u].push_back(v), g[v].push_back(u);		
		sz[v] += sz[u];
		mp.erase(mp.find(d[u]));
	}
	for (int i = 1; i <= n; ++i) rd[i] = -1;
	rd[1] = 0; q.push(1);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int v : g[u]) if (rd[v] == -1) {
			rd[v] = rd[u] + 1; q.push(v);
		}
	}
	if (accumulate(rd + 1, rd + 1 + n, 0LL) != d[1]) {
		return cout << -1 << '\n',0;
	}
	for (int u = 1; u <= n; ++u) {
		for (int v : g[u]) if (u < v) {
			cout << u << ' ' << v << '\n';
		}
	} 
}
