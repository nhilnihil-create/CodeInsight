#define _CRT_SECURE_NO_WARNINGS
#define MOD 998244353
#define INF 100000000
#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <bitset>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <functional>
#include <algorithm>
#include <iterator>
#include <cstdio>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <chrono>
#include <random>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef pair<int, int> pi;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
#define FOR(i,a,b) for(ll i=(a);i<(b);++i)
#define RFOR(i,a,b) for(ll i=(a);i>(b);i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,n-1,-1)
#define ALL(obj) (obj).begin(), (obj).end()
#define SZ(x) ((int)(x).size())
#define pb push_back
#define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T & a, const T & b) { if (b < a) { a = b; return 1; } return 0; }

inline ll madd(ll a, ll b) {
	a %= MOD; b %= MOD;
	return (a + b) % MOD;
}
inline ll msub(ll a, ll b) {
	a %= MOD; b %= MOD;
	a += MOD;
	return (a - b) % MOD;
}
inline ll mmul(ll a, ll b) {
	a %= MOD; b %= MOD;
	return (a * b) % MOD;
}
inline ll mpow(ll a, ll r) {
	long long res = 1;
	while (r > 0) {
		if (r & 1) res = res * a % MOD;
		a = a * a % MOD;
		r >>= 1;
	}
	return res;
}
inline ll minv(ll a) {
	a %= MOD;
	ll b = MOD, u = 0, v = 1;
	while (a) {
		ll t = b / a;
		b -= t * a; swap(a, b);
		u -= t * v; swap(u, v);
	}
	if (u < 0) u += MOD;
	return u;
}
inline ll mdiv(ll a, ll b) {
	a %= MOD;
	a *= minv(b);
	return a % MOD;
}

struct UnionFind {
	vector<int> data;
	UnionFind(int size) : data(size, -1) { }
	bool unite(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	int root(int x) {
		return data[x] < 0 ? x : data[x] = root(data[x]);
	}
	int size(int x) {
		return -data[root(x)];
	}
};
/*
int vs[200001];
int depth[200001];
int id[100001];
vvi G;
int rmqdat[200001];
int rmqind[200001];

void dfs(int v, int p, int d, int& k) {
	id[v] = k;
	vs[k] = v;
	depth[k++] = d;
	REP(i, G[v].size()) {
		if (G[v][i] != p) {
			dfs(G[v][i], v, d + 1, k);
			vs[k] = v;
			depth[k++] = d;
		}
	}
}

void init(int V) {
	int k = 0;
	dfs(0, -1, 0, k);
}

void rmq_init(int* dat, int datlen) {
	int n = 1;
	while (n < datlen) n *= 2;
	REP(i, n * 2) rmqdat[i] = 1000000;
	for (int i = 0, j = n - 1; i < datlen; i++, j++) {
		rmqdat[j] = dat[i];
		rmqind[j] = i;
	}
	RREP(i, n - 1) {
		if (rmqdat[i * 2 + 1] < rmqdat[i * 2 + 2]) {
			rmqdat[i] = rmqdat[i * 2 + 1];
			rmqind[i] = rmqind[i * 2 + 1];
		}
		else {
			rmqdat[i] = rmqdat[i * 2 + 2];
			rmqind[i] = rmqind[i * 2 + 2];
		}
	}
}

pi query(int a, int b, int k, int l, int r) {
	if (r <= a || b <= l) return pi(1000000, -1);
	if (a <= l && r <= b) return pi(rmqdat[k], rmqind[k]);
	else {
		pi pl = query(a, b, k * 2 + 1, l, (l + r) / 2);
		pi pr = query(a, b, k * 2 + 2, (l + r) / 2, r);
		if (pl.first < pr.first) return pl;
		else return pr;
	}
}

int lca(int u, int v, int n) {
	return vs[query(min(id[u], id[v]), max(id[u], id[v]) + 1, 0, 0, n * 2 - 1).second];
}
	int n, u, v;
	cin >> n;
	REP(i, n + 1) G.push_back(vi());
	REP(i, n - 1) {
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	init(n);
	rmq_init(depth, n * 2 - 1);
	int q;
	cin >> q;
	REP(i, q) {
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
	}
*/

/*
ll gcd(ll a, ll b) {
	if (a < 0) a *= -1;
	if (b < 0) b *= -1;
	if (a < b) {
		ll c = b;
		b = a; a = c;
	}
	if ((a % b) == 0) return b;
	else return gcd(b, a % b);
}

pll kiyaku(ll a, ll b) {
	if (a == 0) return pll(0, 1);
	if (b == 0) return pll(1, 0);
	return pll(a / gcd(a, b), b / gcd(a, b));
}
*/

template< typename T > struct BinaryIndexedTree {
	vector< T > data;

	BinaryIndexedTree(int sz) {
		data.assign(++sz, 0);
	}

	T sum(int k) { //inclusive
		T ret = 0;
		for (++k; k > 0; k -= k & -k) ret += data[k];
		return (ret);
	}

	void add(int k, T x) {
		for (++k; k < data.size(); k += k & -k) data[k] += x;
	}
};

template< typename Monoid >
struct SegmentTree {
	using F = function< Monoid(Monoid, Monoid) >;

	int sz;
	vector< Monoid > seg;

	const F f;
	const Monoid M1;

	SegmentTree(int n, const F f, const Monoid& M1) : f(f), M1(M1) {
		sz = 1;
		while (sz < n) sz <<= 1;
		seg.assign(2 * sz, M1);
	}

	void set(int k, const Monoid& x) {
		seg[k + sz] = x;
	}

	void build() {
		for (int k = sz - 1; k > 0; k--) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	void update(int k, const Monoid& x) {
		k += sz;
		seg[k] = x;
		while (k >>= 1) {
			seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
		}
	}

	Monoid query(int a, int b) {
		Monoid L = M1, R = M1;
		for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if (a & 1) L = f(L, seg[a++]);
			if (b & 1) R = f(seg[--b], R);
		}
		return f(L, R);
	}

	Monoid operator[](const int& k) const {
		return seg[k + sz];
	}

	template< typename C >
	int find_subtree(int a, const C& check, Monoid& M, bool type) {
		while (a < sz) {
			Monoid nxt = type ? f(seg[2 * a + type], M) : f(M, seg[2 * a + type]);
			if (check(nxt)) a = 2 * a + type;
			else M = nxt, a = 2 * a + 1 - type;
		}
		return a - sz;
	}


	template< typename C >
	int find_first(int a, const C& check) {
		Monoid L = M1;
		if (a <= 0) {
			if (check(f(L, seg[1]))) return find_subtree(1, check, L, false);
			return -1;
		}
		int b = sz;
		for (a += sz, b += sz; a < b; a >>= 1, b >>= 1) {
			if (a & 1) {
				Monoid nxt = f(L, seg[a]);
				if (check(nxt)) return find_subtree(a, check, L, false);
				L = nxt;
				++a;
			}
		}
		return -1;
	}

	template< typename C >
	int find_last(int b, const C& check) {
		Monoid R = M1;
		if (b >= sz) {
			if (check(f(seg[1], R))) return find_subtree(1, check, R, true);
			return -1;
		}
		int a = sz;
		for (b += sz; a < b; a >>= 1, b >>= 1) {
			if (b & 1) {
				Monoid nxt = f(seg[--b], R);
				if (check(nxt)) return find_subtree(b, check, R, true);
				R = nxt;
			}
		}
		return -1;
	}
};

/*
ll fact[MAXN_COMBI+1];
void init_combi(void){
	fact[0] = 1;
	REP(i, MAXN_COMBI) fact[i + 1] = mmul(fact[i], i+1);
	REP(i, n) {
		res = madd(res, combi(n / (i + 1)-1, k-1));
	}
}
inline ll combi(int a, int b) {
	if (a < b) return 0;
	return mmul(fact[a], mmul(minv(fact[b]), minv(fact[a - b])));
}
*/

int main() {
	optimize_cin();
	int n, m;
	cin >> n >> m;
	vvi arr(n, vi(m));
	stack<pi> st1, st2;
	int cnt=0;
	REP(i, n) {
		string s;
		cin >> s;
		REP(j, m) {
			if (s[j] == '#') {
				arr[i][j] = 1;
				st1.push(pi(i, j));
				cnt++;
			}
		}
	}
	if (cnt == n * m) {
		cout << 0 << endl;
		return 0;
	}
	int res = 0;
	vector<pi> d;
	d.push_back(pi(-1, 0));
	d.push_back(pi(1, 0));
	d.push_back(pi(0, 1));
	d.push_back(pi(0, -1));
	while (cnt < n * m) {
		while (!st1.empty()) {
			pi p = st1.top();
			st1.pop();
			for(pi dp : d){
				int ii = p.first + dp.first;
				int jj = p.second + dp.second;
				ii = min(ii, n - 1);
				ii = max(ii, 0);
				jj = min(jj, m - 1);
				jj = max(jj, 0);
				if (arr[ii][jj] == 0) {
					arr[ii][jj] = 1;
					cnt++;
					st2.push(pi(ii, jj));
				}
			}
		}
		st1 = st2;
		st2 = stack<pi>();
		res++;
	}
	cout << res << endl;
	return 0;
}
