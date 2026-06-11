//IOI 2021

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2 * 100 * 1000 + 17;

int n, m, par[MAXN], root, IN[MAXN], lev[MAXN];
bool mark[MAXN];
vector<int> adj[MAXN];

void dfs(int v, int le = 0) {
	mark[v] = true;
	for (auto u : adj[v])
		if (!mark[u] && IN[u] == 1) {
			if (le + 1 > lev[u])
				lev[u] = le + 1, par[u] = v;
			IN[u]--;
			dfs(u, lev[u]);
		}
		else if (!mark[u]) {
			if (le + 1 > lev[u])
				lev[u] = le + 1, par[u] = v;
			IN[u]--;
		}
		else
			;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i < n + m; i++) {
		int v, u;
		cin >> v >> u;
		adj[v].pb(u);
		IN[u]++;
	}
	for (int i = 1; i <= n; i++)
		if (!IN[i])
			root = i;
	dfs(root);
	for (int i = 1; i <= n; i++)
		cout << par[i] << endl;
	return 0;
}
