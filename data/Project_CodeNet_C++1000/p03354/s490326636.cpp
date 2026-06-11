#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using V = vector<int>;
using VV = vector<V>;
using VVV = vector<VV>;
using VL = vector<ll>;
using VVL = vector<VL>;
using VVVL = vector<VVL>;
template<class T> using P = pair<T, T>;
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define REP(i,k,n) for(int i=(k);i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define output(x,y) cout << fixed << setprecision(y) << x << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
const ll MOD = 1e9 + 7;
// const ll MOD = 998244353;
ll upper = MOD + MOD;
ll under = -upper;
ll UPPER = MOD * MOD;
ll UNDER = -UPPER;
const long double pi = 3.141592653589793;
struct UnionFind {
	vector<int> par;
	UnionFind(int n) : par(n) {
		par = vector<int>(n, -1);
	}
	int root(int x) {
		if (par[x] < 0) return x;
		else return root(par[x]);
	}
	int size(int x) {
		return -par[root(x)];
	}
	bool unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		if (rx == ry) return false;
		if (size(rx) < size(ry)) swap(rx, ry);
		par[rx] += par[ry];
		par[ry] = rx;
		return true;
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	int count() {
		int res = 0;
		rep(i, par.size()) {
			if (par[i] < 0) res++;
		}
		return res;
	}
};
int main() {
	int n, m;
	cin >> n >> m;
	V p(n);
	rep(i, n) {
		cin >> p[i];
		p[i]--;
	}
	UnionFind G(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		G.unite(a, b);
	}
	// 同じ連結成分にある頂点どうしは好きにいじることができる
	int ans = 0;
	rep(i, n) {
		if (G.same(p[i], i)) ans++;
	}
	cout << ans << endl;
	return 0;
}