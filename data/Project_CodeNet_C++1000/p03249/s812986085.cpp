#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<19, mod = 1e9 + 7;
int n;
vi g[maxn];
ll t = 0;
void dfs(int v, int p = -1, int h = 0) {
	t += h;
	for(auto &i : g[v]) if(i != p) dfs(i, v, h + 1);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	vi a(n), sz(n+1, 1);
	map<ll, int> id;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		id[a[i]] = i+1;
	}
	sort(rall(a));
	vector<pair<int, int>> edges;
	for(auto x : a) {
		int i = id[x];
		if(sz[i] == n) continue;
		ll nd = x + 2*sz[i] - n;
		if(nd < x && id.count(nd)) {
			edges.pb({i, id[nd]});
			sz[id[nd]] += sz[i];
		}
	}
	for(auto i : edges) {
		int x = i.first, y = i.second;
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(id[a.back()]);
	if(edges.size() != n-1 || t != a.back()) return cout << -1, 0;
	for(auto i : edges) cout << i.first << " " << i.second << '\n';
}
