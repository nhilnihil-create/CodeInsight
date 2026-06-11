#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef double db;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
typedef unsigned long long ull;

typedef pair < db, db > pdd;
typedef pair < db, ld > pdl;
typedef pair < ld, db > pld;
typedef pair < ld, ld > ldp;

typedef pair < ll, ll > pll;
typedef pair < int, ll > pil;
typedef pair < ll, int > pli;
typedef pair < int, int > pii;

#define F first
#define S second

#define en end()
#define bg begin()

#define rev reverse
#define mp make_pair
#define pb push_back

#define y1 y1234567890
#define um unordered_map

#define all(x) x.bg, x.en
#define sz(x) (int)x.size()
#define len(x) (int)strlen(x)

#define sqr(x) ((x + 0ll) * (x))
#define sqrd(x) ((x + 0.0) * (x))

#define forn(i, n) for (int i = 1; i <= n; i++)

const ll inf = (ll)1e18;
const ll mod = (ll)1e9 + 7;

const db eps = (db)1e-9;
const db pi = acos(-1.0);

const int dx[] = {0, 0, 1, 0, -1};
const int dy[] = {0, 1, 0, -1, 0};

const int N = 100500;

int n, p[N], cnt[N];
vector < int > g[N];
map < ll, int > pos;
ll d[N], dp[N], dp1[N];

inline bool cmp(int i, int j) {
	return d[i] < d[j];
}

void dfs(int v, int pr = -1) {
	cnt[v] = 1;
	for (auto to : g[v]) {
		if (to == pr)
			continue;
		dfs(to, v);
		cnt[v] += cnt[to];
		dp[v] += dp[to] + cnt[to];
	}
}

void dfs1(int v, int pr = -1) {
	ll sum = 0;
	for (auto to : g[v])
		if (to != pr)
			sum += dp[to];
	for (auto to : g[v]) {
		if (to == pr)
			continue;
		dp1[to] = dp1[v] + sum - dp[to] + 2 * (cnt[v] - cnt[to] - 1) + n - cnt[v] + 1;
		dfs1(to, v);
	}
}

int main() {
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	//freopen(".err", "w", stderr);

	//srand(time(NULL));

	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//cout << setprecision(10) << fixed;
	
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> d[i];
		p[i] = i;
	}

	sort(p + 1, p + 1 + n, &cmp);

	for (int i = 1; i <= n; i++) {
		pos[d[p[i]]] = i;
		cnt[p[i]] = 1;
	}

	for (int i = n; i > 1; i--) {
		ll val = d[p[i]] + cnt[p[i]] + cnt[p[i]] - n;
		if (!pos.count(val) || val >= d[p[i]]) {
			cout << -1;
			return 0;
		}
		int pr = pos[val];
		cnt[p[pr]] += cnt[p[i]];
		g[p[pr]].pb(p[i]);
		g[p[i]].pb(p[pr]);
	}

	dfs(1);
	dfs1(1);

	for (int i = 1; i <= n; i++) {
		if (dp[i] + dp1[i] != d[i]) {
			cout << -1;
			return 0;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (auto j : g[i])
			if (i < j)
				cout << i << " " << j << "\n";
	}
	
	//cerr << (clock() + 0.0) / CLOCKS_PER_SEC;

	return 0;
}
