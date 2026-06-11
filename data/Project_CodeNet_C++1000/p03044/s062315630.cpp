#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pi pair<ll,ll>
#define pii pair<ll,pi>
#define pb push_back
#define mk make_pair
const int siz = 1e5 + 7;
vector<pi>adj[siz];
ll dis[siz];
bool vis[siz];
int n;
void dfs(int v) {
	vis[v] = true;
	for (auto k : adj[v]) {
		if (!vis[k.fi]) {
			vis[k.fi] = true;
			dis[k.fi] = max(dis[k.fi], dis[v] + k.se);
			dfs(k.fi);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i <= siz; i++)vis[i] = false;
	for (int i = 0; i < n - 1; i++) {
		ll u, v, w;
		cin >> u >> v >> w;
		adj[u].pb(mk(v, w));
		adj[v].pb(mk(u, w));
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		if (dis[i] & 1)
			cout << "1" << endl;
		else
			cout << "0" << endl;
	}
}

