#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
const int MAXN = 1e5+1;
const int INF = 1e9 + 7;
vector<int> dp;
vector<vector<int> > adj;
vector<int> ind;
vector<int> outd;
int N, M;
int f(int s) {
	int& ret = dp[s];
	if (ret != -1) return ret;
	if (outd[s] == 0) return ret = 0;
	ret = 1;
	for (int i : adj[s]) {
		ret = max(ret, f(i)+1);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	dp.resize(N+1,-1),ind.resize(N+1,0), outd.resize(N+1,0), adj.resize(N+1);
	for (int i = 0; i < M; ++i) {
		int u, v; cin >> u >> v;
		outd[u]++, ind[v]++, adj[u].push_back(v);
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i) {
		if (ind[i]) continue;
		ans = max(ans, f(i));
	}
	cout << ans << '\n';
	return 0;
}