	#include<bits/stdc++.h>
	using namespace std;
	typedef long long ll;
	typedef long double db;
	#define fi first
	#define se second
	#define pi pair<ll,ll>
	#define pii pair<ll,pi>
	#define pb push_back
	#define mk make_pair
	const int siz = 100;
	vector<int>adj[siz];
	vector<bool> visited(siz);
	vector<int> tin(siz), low(siz);
	int timer;
	int ans;
	int n, m;
	void dfs(int v, int p = -1) {
		visited[v] = true;
		tin[v] = low[v] = timer++;
		for (int to : adj[v]) {
			if (to == p) continue;
			if (visited[to]) {
				low[v] = min(low[v], tin[to]);
			} else {
				dfs(to, v);
				low[v] = min(low[v], low[to]);
				if (low[to] > tin[v])
					ans++;
			}
		}
	}

	void find_bridges() {
		timer = 0;
		visited.assign(n, false);
		tin.assign(n, -1);
		low.assign(n, -1);
		for (int i = 0; i < n; ++i) {
			if (!visited[i])
				dfs(i);
		}
	}
	int main() {
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		find_bridges();
		cout << ans << endl;
	}