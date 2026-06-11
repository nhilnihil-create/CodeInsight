#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(a);i>(b);i--)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
typedef complex<double> com;
const int mod = 1e9 + 7; //998244353
const int inf = 2e9; const ll INF = 4e18;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll a, ll b) { if (!b)return a; else return gcd(b, a % b); }
ll mpow(ll a, ll b) { ll r = 1; a %= mod; while (b) { r = r * ((b % 2) ? a : 1) % mod, a = a * a % mod, b >>= 1; }return r; }

//template
ll Add(ll a, ll b) { return (a + b) % mod; }
ll Dec(ll a, ll b) { return (a - b + mod) % mod; }
ll Mul(ll a, ll b) { return (1LL * a * b) % mod; }
ll Div(ll a, ll b) { return (1LL * a * mpow(b, mod - 2)) % mod; }
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
bool cmp(edge& a, edge& b) { return a.cost < b.cost; }
vector<edge> es; ll MinTreeCost;
UnionFind kruskal(int V) {
	sort(es.begin(), es.end(), cmp);
	UnionFind UF(V);
	for (edge e : es) {
		if (UF.connect(e.u, e.v)) {
			MinTreeCost += e.cost;
		}
	}
	return UF;
}
vector<int> fac, finv;
void factorial(int N) {
	fac.resize(N); finv.resize(N);
	fac[0] = finv[0] = 1;
	rep(i, 1, N)fac[i] = Mul(fac[i - 1], i);
	finv[N - 1] = mpow(fac[N - 1], mod - 2);
	rrep(i, N - 2, -1) finv[i] = Mul(finv[i + 1], i + 1);
}
int nCr(int n, int m) {
	if (m < 0 || n < m) return 0;
	return Mul(Mul(fac[n], finv[m]), finv[n - m]);
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
			cnt += n / 2LL - bi;
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
vector<edge> G[MAX_V]; ll dist[MAX_V];
void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P> > que;
	fill(dist, dist + MAX_V, INF);
	dist[s] = 0;
	que.push(P(0, s));
	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (dist[v] < p.first) continue;
		for (int i = 0; i < G[v].size(); ++i) {
			edge e = G[v][i];
			if (dist[e.v] > dist[v] + e.cost) {
				dist[e.v] = dist[v] + e.cost;
				que.push(P(dist[e.v], e.v));
			}
		}
	}
}
int diameter(vector<vector<edge>>& g) {
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
int bipartite(vector<vector<int>>& g) {
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
struct max_flow {
private:
	struct Edge { int to, cap, rev; };
	int V;
	vector<vector<Edge>> G;
	vector<int> itr, level;
public:
	max_flow(int V) : V(V) { G.assign(V, vector<Edge>()); }

	void add_edge(int from, int to, int cap) {
		G[from].push_back({ to, cap, (int)G[to].size() });
		G[to].push_back({ from, 0, (int)G[from].size() - 1 });
	}

	void bfs(int s) {
		level.assign(V, -1);
		queue<int> q;
		level[s] = 0; q.push(s);
		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (auto& e : G[v]) {
				if (e.cap > 0 && level[e.to] < 0) {
					level[e.to] = level[v] + 1;
					q.push(e.to);
				}
			}
		}
	}

	int dfs(int v, int t, int f) {
		if (v == t) return f;
		for (int& i = itr[v]; i < (int)G[v].size(); ++i) {
			Edge& e = G[v][i];
			if (e.cap > 0 && level[v] < level[e.to]) {
				int d = dfs(e.to, t, min(f, e.cap));
				if (d > 0) {
					e.cap -= d;
					G[e.to][e.rev].cap += d;
					return d;
				}
			}
		}
		return 0;
	}

	int run(int s, int t) {
		int ret = 0, f;
		while (bfs(s), level[t] >= 0) {
			itr.assign(V, 0);
			while ((f = dfs(s, t, inf)) > 0) ret += f;
		}
		return ret;
	}
};
//template end



int main() {
	int n, q; string s; cin >> n >> s >> q;
	rep(i, 0, q) {
		int k; cin >> k;
		ll d = 0, m = 0, c = 0, res = 0;
		rep(i, 0, n) {
			if (s[i] == 'D')d++;
			if (s[i] == 'M')m++,c+=d;
			if (s[i] == 'C')res += c;
			if (i >= k - 1) {
				int idx = i - k + 1;
				if (s[idx] == 'D')d--, c -= m;
				if (s[idx] == 'M')m--;
			}
		}
		printf("%lld\n", res);
	}
	return 0;
}
