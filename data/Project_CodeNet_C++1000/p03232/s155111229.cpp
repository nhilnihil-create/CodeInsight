#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7; //998244353
const int inf = 2e9;
ll mpow(ll a, ll b) { ll r = 1; a %= mod; while (b) { r = r * ((b % 2) ? a : 1) % mod, a = a * a % mod, b >>= 1; }return r; }

//template

class UnionFind {
public:
	vector<int> par;
	UnionFind(int n) {
		par = vector<int>(n, -1);
	}
	int root(int a) {
		if (par[a] < 0) {
			return a;
		}
		else {
			return par[a] = root(par[a]);
		}
	}
	int size(int a) {
		return -par[root(a)];
	}
	bool connect(int a, int b) {
		a = root(a);
		b = root(b);
		if (a == b) {
			return false;
		}
		if (size(a) < size(b)) {
			swap(a, b);
		}
		par[a] += par[b];
		par[b] = a;
		return true;
	}
};
struct edge { int cost, u, v; };
bool comp(edge& e1, edge& e2) {
	return e1.cost < e2.cost;
}
#define MAX_E 200010
edge es[MAX_E]; int V, E;
int kruskal() {
	sort(es, es + MAX_E, comp);
	UnionFind uni(V);
	int res = 0;
	rep(i, 0, E) {
		edge e = es[i];
		if (uni.root(e.u) != uni.root(e.v)) {
			uni.connect(e.u, e.v);
			res += e.cost;
		}
	}
	return res;
}
vector<int> fac, finv;
void factor(int N) {
	fac.resize(N); finv.resize(N);
	fac[0] = finv[0] = 1;
	rep(i, 1, N)fac[i] = 1LL * fac[i - 1] * i % mod;
	finv[N - 1] = mpow(fac[N - 1], mod - 2);
	for (int i = N - 2; i; --i) finv[i] = 1LL * finv[i + 1] * (i + 1) % mod;
}
int nCr(int n, int m) {
	if (m < 0 || n < m) return 0;
	return 1LL * (1LL * fac[n] * finv[m] % mod) * finv[n - m] % mod;
}
ll merge_cnt(vector<int>& a) {
	int n = a.size();
	if (n <= 1) return 0;
	ll cnt = 0;
	vector<int> b(a.begin(), a.begin() + n / 2);
	vector<int> c(a.begin() + n / 2, a.end());
	cnt += merge_cnt(b);
	cnt += merge_cnt(c);
	int ai = 0, bi = 0, ci = 0;
	while (ai < n) {
		if (bi < b.size() && (ci == c.size() || b[bi] <= c[ci])) {
			a[ai++] = b[bi++];
		}
		else {
			cnt += n / 2 - bi;
			a[ai++] = c[ci++];
		}
	}
	return cnt;
}
void fft(vector<com>& x, bool inv) {
	int s = x.size();
	if (s == 1) return;
	else {
		vector<com> even(s / 2), odd(s / 2);
		rep(i, 0, s / 2) {
			even[i] = x[i * 2];
			odd[i] = x[i * 2 + 1];
		}
		fft(even, inv);
		fft(odd, inv);
		com w = 1, w_0 = polar(1.0, (inv ? -1 : 1) * 2LL * M_PI / s);
		int t = s / 2 - 1;
		rep(i, 0, s) {
			x[i] = even[i & t] + w * odd[i & t];
			w *= w_0;
		}
	}
}
#define MAX_V 100010
vector<edge> G[MAX_V]; ll DIST[MAX_V];
void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P> > que;
	fill(DIST, DIST + MAX_V, 1LL * inf * inf);
	DIST[s] = 0;
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (DIST[v] < p.first) continue;
		for (int i = 0; i < G[v].size(); ++i) {
			edge e = G[v][i];
			if (DIST[e.v] > DIST[v] + e.cost) {
				DIST[e.v] = DIST[v] + e.cost;
				que.push(P(DIST[e.v], e.v));
			}
		}
	}
}
bool cross(ll ax, ll ay, ll bx, ll by, ll cx, ll cy, ll dx, ll dy) {
	ll ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
	ll tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
	ll tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
	ll td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);
	return tc * td <= 0LL && ta * tb <= 0LL;
}
int diameter(const vector<vector<edge>>& g) {
	function<P(int, int)> DFS = [&](int prev, int v) {
		P r(0, v);
		rep(i, 0, g[v].size()) {
			edge e = g[v][i];
			if (e.v == prev) continue;
			P tmp = DFS(v, e.v);
			tmp.first += e.cost;
			if (r.first < tmp.first) r = tmp;
		}
		return r;
	};
	P r = DFS(-1, 0);
	P t = DFS(-1, r.second);
	return t.first;
}
int bipartite(const vector<vector<int>>& g) {
	int n = g.size();
	vector<int> color(n, -1);
	int white_cnt = 0;
	function<bool(int, int, int)> DFS = [&](int u, int prev, int c) {
		color[u] = c;
		if (c == 1) white_cnt++;
		for (auto v : g[u]) if (v != prev) {
			if (color[v] == -1) {
				if (!DFS(v, u, 1 - c)) return false;
			}
			else if (color[v] != 1 - c) {
				return false;
			}
		}
		return true;
	};
	if (!DFS(0, -1, 0)) return -1;
	return white_cnt;
}
//template end



int main() {
	int n; cin >> n;
	vector<int> a(n);
	rep(i, 0, n) cin >> a[i];
	vector<ll> sum(n+1,0);
	sum[0] = 1; ll mul = 1;
	rep(i, 1, n+1) {
		mul = (mul * i) % mod;
		sum[i] = (sum[i - 1] + mpow(i + 1, mod - 2)) % mod;
	}
	ll ans = 0;
	rep(i, 0, n) {
		ans = (ans + 1LL * a[i] * (sum[i] + sum[n - 1 - i] - 1)) % mod;
	}
	printf("%lld", (1LL*ans*mul)%mod);
	return 0;
}
