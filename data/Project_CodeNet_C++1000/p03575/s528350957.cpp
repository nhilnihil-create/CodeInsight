#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define rrep(i,n) for(int i=1;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define maxs(a, b) a = max(a, b)
#define mins(a, b) a = min(a, b)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const ll linf = (1ll << 61);
const int inf = 1001001001;
const int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> g(n);
	vector<P> rec(m);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
		rec[i] = P(a, b);
	}
	P p1;
	vector<int> vi(n, 0);
	vector<int> used(n, 0);
	function<void(int)> Dfs = [&](int v) {
		vi[v] = 1;
		used[v] = 1;
		for (int c : g[v]) {
			if (used[c]) continue;
			if (p1 == P(v, c) || p1 == P(c, v)) continue;
			Dfs(c);
		}
	};
	int ans = 0;
	rep(i, m) {
		vi = vector<int>(n, 0);
		used = vector<int>(n, 0);
		p1 = rec[i];
		Dfs(0);
		bool ok = true;
		rep(i, n) if (!vi[i]) ok = false;
		if(!ok) ans++;
	}
	cout << ans << endl;
	return 0;
}
