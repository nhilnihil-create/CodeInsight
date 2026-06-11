#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=100000, M=1e9+7;
int n;
ll dp[mxN][2];
vector<int> adj[mxN];

void dfs(int u=0, int p=-1) {
	dp[u][0]=dp[u][1]=1;
	for (int v : adj[u]) if (v!=p) {
		dfs(v, u);
		dp[u][0]=dp[u][0]*(dp[v][0]+dp[v][1])%M;
		dp[u][1]=dp[u][1]*dp[v][0]%M;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=1, u, v; i<n; ++i) {
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs();
	cout << (dp[0][0]+dp[0][1])%M;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
