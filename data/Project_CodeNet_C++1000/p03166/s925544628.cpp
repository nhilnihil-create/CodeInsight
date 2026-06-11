// Longest Path
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define times(t) int t; cin >> t; while(t--)
#define mod 1000000007

const int MAXN = 1e5 + 5;
vector<int> g[MAXN];
int dp[MAXN], vis[MAXN], N, M;

int dfs(int u) {
	if(vis[u]) return dp[u];
	vis[u] = 1;
	int best = 0;
	for(auto v : g[u]) {
		best = max(best, dfs(v)+1);
	}
	return dp[u] = best;
}

void solve() {
	cin >> N >> M;
	for(int i=1; i<=M; i++) {
		int u, v; cin >> u >> v;
		g[u].push_back(v);
	}
	int best = 0;
	for(int i=1; i<=N; i++)
		best = max(best, dfs(i));
	cout << best << endl;
	return;
}

int main() {
	IOS;
	// #ifndef ONLINE_JUDGE
	// freopen("C:/Gen code/CompProg/input.txt", "r", stdin);
	// freopen("C:/Gen code/CompProg/output.txt", "w", stdout);
	// #endif
	solve();
	return 0;
}