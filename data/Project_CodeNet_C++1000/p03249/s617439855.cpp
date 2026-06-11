#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()


int main() {
#ifdef local
	freopen("in.txt", "r", stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n; cin >> n;
	vector<pair<ll, ll> > d(n);
	for(int i = 0; i < n; i++) {
		ll x; cin >> x;
		d[i] = make_pair(x, i);
	}
	vector<int> sz(n, 1);
	sort(all(d), greater<pair<ll,ll>>());
	vector<pair<int, int> > edges;
	vector<vector<int> > adj(n);
	for(int i = 0; i < n - 1; i++) {
		ll id = d[i].se, dis = d[i].fi;
		int dt = n - 2*sz[id];
		dis -= dt;
		auto it = lower_bound(all(d), pair<ll, ll>(dis, n), greater<pair<ll, ll> >());
		if(it == d.end() || it->fi != dis) {
			cout << "-1\n";
			return 0;
		}
		sz[it->se] += sz[id];
		adj[it->se].push_back(id);
		edges.emplace_back(id + 1, it->se + 1);
	}
	function<ll(int)> dfs = [&](int u) {
		ll ret = 0;
		for(auto &v : adj[u]) {
			ret += dfs(v) + sz[v];
		}
		return ret;
	};
	if(dfs(d[n-1].se) != d[n-1].fi) {
		cout << "-1\n";
		return 0;
	}
	sort(all(edges));
	for(auto &e : edges) {
		cout << e.fi << ' ' << e.se << '\n';
	}
	return 0;
}
