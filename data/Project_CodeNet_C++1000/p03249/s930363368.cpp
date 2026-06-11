#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define str string
#define fi first
#define se second
#define pb push_back
#define SET(a, b) memset(a, b, sizeof(a))
#define eps 1e-6
#define pi atan(1) * 4
#define mod 1000000007
#define inf 1000000000
#define llinf 1000000000000000000
#define FOR(i, a, b, c) for (int i = (a); i <= (b); i += (c))
#define FORD(i, a, b, c) for (int i = (a); i >= (b); i -= (c))
#define FORl(i, a, b, c) for (ll i = (a); i <= (b); i += (c))
#define FORDl(i, a, b, c) for (ll i = (a); i >= (b); i -= (c))
using namespace std;
int n;
map<ll, ll> inp;
pll order[100005];
int sze[100005];

vector<int> edges[100005];
int sub[100005];
int dep[100005];
ll dfs (int u, int p) {
	ll s = dep[u];
	int sz = 1;
	for (auto v : edges[u]) {
		if (v == p) continue;
		dep[v] = dep[u] + 1;
		s += dfs(v, u);
		sz += sub[v];
	}
	sub[u] = sz;
	return s;
}
ll pos[100005];
int it = 0;
void dfs2 (int u, int p, ll sd) {
	pos[++it] = sd;
	for (auto v : edges[u]) {
		if (v == p) continue;
		dfs2(v, u, sd - sub[v] + (n - sub[v]));
	}
}
int main () {
	scanf("%d", &n);
	FOR(i, 1, n, 1) {
		ll t;
		scanf("%lld", &t);
		order[i] = {t, i};
		inp[t] = i;
		sze[i] = 1;
	}
	sort(order + 1, order + n + 1);
	vector<pii> elist;
	FORD(i, n, 2, 1) {
		auto u = order[i];
		int s = sze[u.se];
		ll nd = u.fi - (n - sze[u.se]) + sze[u.se];
		if (nd > u.fi || inp.find(nd) == inp.end() || inp[nd] == u.se) {
			printf("-1\n"); return 0;
		}
		int v = inp[nd];
		elist.pb({u.se, v});
		edges[u.se].pb(v); edges[v].pb(u.se);
		sze[v] += sze[u.se];
	}

	dep[1] = 0;
	ll sumd = dfs(1, -1);
	dfs2(1, -1, sumd);
	sort(pos + 1, pos + n + 1);
	FOR(i, 1, n, 1) {
		if (order[i].fi != pos[i]) {
			printf("-1\n"); return 0;
		}
	}

	for (auto e : elist) {
		printf("%d %d\n", e.fi, e.se);
	}
	return 0;
}