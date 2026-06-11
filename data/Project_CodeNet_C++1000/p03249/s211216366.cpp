#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n;
ll d[100005];
map <ll, int> st;
vector <pii> e;
int siz[100005];
vi g[100005];

ll dfs(int u, int p) {
	ll dd = 0;
	rep(i, g[u].size()) if (g[u][i] != p) dd += siz[g[u][i]] + dfs(g[u][i], u);
	return dd;
}

int main() {
	n = read();
	rep(i, n) scanf("%lld", &d[i]);
	rep(i, n) st[d[i]] = i;
	int rt = st.begin() -> second;
	rep(i, n) siz[i] = 1;
	while (!st.empty()) {
		ll mx = st.rbegin() -> second;
		if (mx == rt) break;
		st.erase(d[mx]);
		ll nxd = d[mx] - (n - 2 * siz[mx]);
		if (!st.count(nxd)) {
			puts("-1");
			return 0;
		}
		siz[st[nxd]] += siz[mx];
		e.pb(mp(mx, st[nxd]));
		g[mx].pb(st[nxd]); g[st[nxd]].pb(mx);
	}
	if (dfs(rt, -1) != d[rt]) {
		puts("-1");
		return 0;
	}
	rep(i, e.size()) printf("%d %d\n", e[i].first + 1, e[i].second + 1);
	return 0;
}