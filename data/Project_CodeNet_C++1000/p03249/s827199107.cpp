#include <bits/stdc++.h>
#define N 100005

using namespace std;
typedef long long ll;

template <class T> inline void read(T &x) {
	char ch; bool flag = false;
	while (!isdigit(ch = getchar())) flag |= ch == '-';
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	if (flag) x = -x;
}

inline int input() {
	int x; char ch; bool flag = false;
	while (!isdigit(ch = getchar())) flag |= ch == '-';
	for (x = ch ^ 48; isdigit(ch = getchar()); x = x * 10 + (ch ^ 48));
	return flag ? -x : x;
}

const int mod = 1e9 + 7;
inline int add(int x, int y) { x += y; return x >= mod ? x - mod : x; }
inline void inc(int &x, int y) { x += y; x -= x >= mod ? mod : 0; }

inline int Power(int x, int y) {
	int res = 1;
	while (y) {
		if (y & 1) res = (ll) res * x % mod;
		x = (ll) x * x % mod, y >>= 1;
	} return res;
}

template <class T> void chkmax(T &x, T y) { x = x > y ? x : y; }
template <class T> void chkmin(T &x, T y) { x = x < y ? x : y; }
template <class T> T gcd(T x, T y) { return !y ? x : gcd(x % y, y); }

ll n, Dis;
ll d[N], dis[N];
ll size[N], fa[N];
map<ll, ll> mp;
vector<ll> G[N];
	
void FAIL() {
	puts("-1");
	exit(0);
}

ll id(ll x) { return mp[d[x]]; }
inline void AddEdge(int x, int y) { G[x].push_back(y); }

inline void dfs(int u) {
	Dis += dis[u];
	for (int v : G[u]) dis[v] = dis[u] + 1, dfs(v);
}

bool check() {
	dfs(1);
	return Dis == d[1];
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	for (ll i = 1; i <= n; ++i) size[i] = 1;
	for (ll i = 1; i <= n; ++i) {
		cin >> d[i], mp[d[i]] = i;
		if (d[i] > (ll) n * (n - 1) / 2) FAIL();
	}
	sort(d + 1, d + n + 1);

	for (ll i = n; i > 1; --i) {
		ll vf = d[i] - n + size[i] + size[i];
		if (vf >= d[i]) FAIL();
		fa[i] = lower_bound(d + 1, d + n + 1, vf) - d;
		if (d[fa[i]] != vf) FAIL();
		size[fa[i]] += size[i];
	}

	for (ll i = 2; i <= n; ++i)
		AddEdge(fa[i], i);
	if (!check()) FAIL();
	else for (ll i = 2; i <= n; ++i)
		printf("%lld %lld\n", id(i), id(fa[i]));
	return 0;
}
			













