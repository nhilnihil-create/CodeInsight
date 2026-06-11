#include <iostream>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cstring>
#include<string>
#include<cassert>
#include<cmath>
#include<climits>
#include<iomanip>
#include<bitset>
#include<unordered_map>

using namespace std;

#define rep(i,m,n) for(int (i)=(int)(m);(i)<(int)(n);(i)++)
#define rep2(i,m,n) for(int (i)=(int)(n)-1;(i)>=(int)(m);(i)--)
#define REP(i,n) rep(i,0,n)
#define FOR(i,c) for(decltype((c).begin())i=(c).begin();i!=(c).end();++i)
#define ll long long
#define ull unsigned long long
#define all(hoge) (hoge).begin(),(hoge).end()
#define en '\n'
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = 998244353;
typedef vector<ll> Array;
typedef vector<Array> Matrix;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;


template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

struct Edge {
	ll to, cap, rev;
	Edge(ll _to, ll _cap, ll _rev) {
		to = _to; cap = _cap; rev = _rev;
	}
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void add_edge(Graph& G, ll from, ll to, ll cap, bool revFlag, ll revCap) {
	G[from].push_back(Edge(to, cap, (ll)G[to].size()));
	if (revFlag)G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}


ll dfs(Graph& g, ll v,Array& c) {
	bool flag = true;
	for (auto e : g[v]) {
		if (c[e.to] == -1) {
			c[e.to] = !c[v];
			if (!dfs(g, e.to, c)) flag = false;
		}
		else {
			if (c[e.to] == c[v]) flag = false;
		}
	}
	return flag;
}

void solve() {
	ll n, m;
	cin >> n >> m;
	
	Graph g(n);
	
	REP(i, m) {
		ll a, b;
		cin >> a >> b;
		a--; b--;
		add_edge(g, a, b, 1, true, 1);
	}
	Array c(n, -1);
	c[0] = 0;
	if (dfs(g, 0, c)) {
		ll con = 0;
		for (auto i : c)if (i == 0) con++;
		cout << con * (n - con) - m << en;
	}
	else {
		cout << n * (n - 1) / 2 - m << en;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solve();
	//int t; cin >> t; REP(i, t) solve();

	return 0;
}
