#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
typedef long long lint;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<lint, lint> pll;
typedef unsigned long long ulint;
#define endl '\n'
#define fst first
#define sed second
#define pb push_back
#define mp make_pair
#define rint register int
#define newline putchar('\n')
#define leave_space putchar(' ')
#define all(x) (x).begin(), (x).end()
#define reveal(x) cerr << #x << " = " << (x) << endl
#define rep(it, f, e) for (rint it = (f); it <= (e); ++it)
#define per(it, f, e) for (rint it = (f); it >= (e); --it)
const int MAXN = 1e5 + 10;
pll p[MAXN];
int sz[MAXN];
map<lint, int> rec;
vector<int> edge[MAXN];
#define D fst
#define P sed
vector<pii> opt;
lint res = 0;
inline void dfs(int u, int par, int dep) {
	res += dep;
	for (auto v : edge[u]) {
		if (v == par) continue;
		dfs(v, u, dep + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	rep (i, 1, n) {
		cin >> p[i].D;
		p[i].P = i;
		if (rec.find(p[i].D) != rec.end()) {
			cout << -1 << endl;
			return 0;
		}
		rec[p[i].D] = p[i].P;
	}
	sort(p + 1, p + n + 1, greater<pll>());
	fill(sz + 1, sz + n + 1, 1);
	rep (i, 1, n - 1) {
		int u = p[i].P;
		if (n - sz[u] - sz[u] <= 0) {
			cout << -1 << endl;
			return 0;
		} 
		lint diff = p[i].D - (n - sz[u] - sz[u]);
		if (rec.find(diff) == rec.end()) {
			cout << -1 << endl;
			return 0;
		}
		int v = rec[diff];
		opt.pb(pii(u, v));
		edge[u].pb(v);
		edge[v].pb(u);
		sz[v] += sz[u];
	}
	dfs(p[n].P, 0, 0);
	if (res != p[n].D) {
		cout << -1 << endl;
		return 0;
	}
	for (auto &v : opt) {
		if (v.fst > v.sed) swap(v.fst, v.sed);
	}
	sort(all(opt));
	for (auto &v : opt) {
		cout << v.fst << ' ' << v.sed << endl;
	}
	return 0;
}