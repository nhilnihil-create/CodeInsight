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

int n;
vector<P> g[100005];
vector<int> ans(100005);

void dfs(int v, int now = 1, int p = -1) {
	ans[v] = now;
	for (auto& c : g[v]) {
		if (c.first == p) continue;
		if (c.second % 2 == 1) dfs(c.first, now ^ 1, v);
		else dfs(c.first, now, v);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	rep(i, n - 1) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		g[a].push_back(P(b, c));
		g[b].push_back(P(a, c));
	}
	dfs(0);
	rep(i, n) printf("%d\n", ans[i]);
	return 0;
}
