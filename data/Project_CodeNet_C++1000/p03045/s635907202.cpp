#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
const int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
const int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n);
	rep(i, m) {
		int x, y, z;
		cin >> x >> y >> z;
		x--, y--;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	vector<int> seen(n);
	int ans = 0;
	rep(i, n) {
		queue<int> que;
		if (seen[i]) continue;
		ans++;
		seen[i] = 1;
		que.push(i);
		while (!que.empty()) {
			int v = que.front();
			que.pop();
			for (auto nv : G[v]) {
				if (seen[nv]) continue;
				que.push(nv);
				seen[nv] = 1;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}