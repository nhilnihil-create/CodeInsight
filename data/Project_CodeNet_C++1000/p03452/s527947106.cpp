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
const int siz = 1e5 + 7;
vector<pi>adj[siz];
bool vis[siz];
int dis[siz];
int n, m;
bool ok;
void dfs(int v) {
	vis[v] = true;
	for (auto k : adj[v]) {
		if (!vis[k.fi]) {
			dis[k.fi] = dis[v] + k.se;
			dfs(k.fi);
		}
		else {
			if (dis[k.fi] != dis[v] + k.se) {
				ok = true;
				return ;
			}
		}

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
		int l, r, m;
		cin >> l >> r >> m;
		adj[l].pb({r, m});
		adj[r].pb({l, -m});
	}
	for (int i = 1; i <= n; i++) {
		if (!vis[i])dfs(i);
	}
	if (ok)
		cout << "No" << endl;
	else
		cout << "Yes" << endl;
}