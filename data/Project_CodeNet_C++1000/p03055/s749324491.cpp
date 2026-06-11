#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define REP(i, a) FOR(i, 0, a - 1)
using PII = pair<int, int>;
#define ST first
#define ND second

vector<vector<int>> graph;

PII dfs(int v, int d = 0, int p = -1) {
	PII ans = {1, v};
	for(int u : graph[v]) {
		if(u != p) {
			PII ret = dfs(u, d + 1, v);
			ret.ST += 1;
			ans = max(ans, ret);
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	graph.resize(n);
	REP(i, n - 1) {
		int a, b;
		cin >> a >> b;
		graph[a - 1].emplace_back(b - 1);
		graph[b - 1].emplace_back(a - 1);
	}

	PII x = dfs(0);
	PII y = dfs(x.ND);

	vector<int> dp(y.ST + 1);
	dp[1] = 1;

	FOR(i, 3, y.ST) dp[i] = (!dp[i - 1] || !dp[i - 2]);
	if(dp[y.ST]) cout << "First\n";
	else cout << "Second\n";
}
