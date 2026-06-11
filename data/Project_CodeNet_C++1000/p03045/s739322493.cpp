#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

// dfs（深さ優先探索）
// https://qiita.com/drken/items/4a7869c5e304883f539b
vector<bool> seen;
void dfs(vector<vector<int>> &g, int v) {
	seen[v] = true;
	for(auto nv: g[v]) {
		if(seen[nv]) continue;
		dfs(g, nv);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> x(m), y(m), z(m);
	rep(i, m) cin >> x[i] >> y[i] >> z[i];
	vector<vector<int>> g(n);
	rep(i, m) {
		x[i]--; y[i]--;
		g[x[i]].push_back(y[i]);
		g[y[i]].push_back(x[i]);
	}
	int ans = 0;
	seen.assign(n, false);
	rep(i, n) {
		if (seen[i] == false) {
			dfs(g, i);
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}