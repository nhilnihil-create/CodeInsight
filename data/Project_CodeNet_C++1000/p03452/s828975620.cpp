#include<bits/stdc++.h>
using namespace std;

#define int long long 

#define fs first
#define sc second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define pb push_back
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MP make_pair
#define sqr(x) ((x) * (x))
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 100;
vector<pair<int, int>> g[N], rg[N];
vector<int> clr(N), ord, dist(N), used(N);
bool cycle = false;

void dfs(int v) {
	clr[v] = 1;
	for (auto i : g[v]) {
		int u = i.fs;
		if (clr[u] == 0) {
			dfs(u);
		} else if (clr[u] == 1) {
			cycle = true;
		}
	}
	clr[v] = 2;
	ord.pb(v);
}

void dfs1(int v) {
	used[v] = 1;
	for (auto i : g[v]) {
		int u, d;
		tie(u, d) = i;
		if (!used[u]) {
			dist[u] = dist[v] + d;
			dfs1(u);
		}
	}	
}

signed main() {
	fastio;
	#ifdef FlameDragon
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v, u, d;
		cin >> v >> u >> d;
		v--; u--;
		g[v].pb(MP(u, d));
		rg[u].pb(MP(v, -d));
	}

	for (int i = 0; i < n; i++) {
		if (clr[i] == 0) {
			dfs(i);
		}
	}
	if (cycle) {
		cout << "No\n";
		return 0;
	}
	reverse(all(ord));
	fill(all(used), 0);
	for (int i = 0; i < n; i++) {
		int v = ord[i];
		if (!used[v]) {
			dfs1(v);
		}
	}

	for (int v = 0; v < n; v++) {
		for (auto i : g[v]) {
			int u, d;
			tie(u, d) = i;
			if (dist[v] + d != dist[u]) {
				cout << "No\n";
				return 0;
			}
		}
	}
	cout << "Yes\n";
}