#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200010;
int N;
bool dp[MAXN];
vector<int> adj[MAXN];
int s, md;

void dfs(int cur, int prv, int d) {
	if (d > md) {
		s = cur;
		md = d;
	}
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		dfs(nxt, cur, d+1);
	}
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int u, v; cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	dfs(1, -1, 1);
	dfs(s, -1, 1);

	dp[0] = false;
	dp[1] = true;
	dp[2] = false;
	for (int i = 3; i <= md; i++) {
		dp[i] = (!dp[i-1] || !dp[i-2]);
	}
	if (dp[md]) {
		cout << "First" << endl;
	} else {
		cout << "Second" << endl;
	}

	return 0;
}
