// me & god
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

const int N = 1e5 + 10;

int n, m;
vector <int> v, adj[N];
set <int> p[N];
bool mark[N];

void dfs(int u, int k) {
	mark[u] = true;
	p[k].insert(u);
	for (auto x: adj[u])
		if (!mark[x])
			dfs(x, k);
}

int main() {
	ios_base :: sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		a--;
		v.push_back(a);
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[v].push_back(u);
		adj[u].push_back(v);
	}
	for (int i = 0; i < n; i++)
		if (!mark[i])
			dfs(i, i);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int si = p[i].size();
		vector <int> l;
		for (auto x: p[i])
			l.push_back(v[x]);
		for (int j = 0; j < l.size(); j++)
			p[i].erase(l[j]);
		ans += si - p[i].size();
	}	
	cout << ans;
	return 0;
}