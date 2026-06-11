#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef pair<ll, ll> P;
#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i <= b; i++)
#define out(x) std::cout << x << '\n'
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = INT_MAX / 2;
const ll  inf = LLONG_MAX / 2;
const int mod = 1000000007;
const int MAX_N = 101010;
const double PI = acos(-1);

struct UnionFind {
	std::vector<int> par;
	UnionFind(int N) 
		: par(N)
	{
		for (int i = 0; i < N; i++) {
			par[i] = i;
		}
	}
	int root(int x) {
		if (par[x] == x) return x;
		return par[x] = root(par[x]);
	}
	void unite(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		if (rx != ry) {
			par[rx] = ry;
		}
	}
	bool same(int x, int y) {
		int rx = root(x);
		int ry = root(y);
		return rx == ry;
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> E(m);
	rep(i, m) {
		cin >> E[i].first >> E[i].second;
		E[i].first--;
		E[i].second--;
	}

	int ans = 0;
	for (int i = 0; i < m; i++) {
		UnionFind uf(n);
		for (int j = 0; j < m; j++) {
			if (i != j && 
				!uf.same(E[j].first, E[j].second)) {
				uf.unite(E[j].first, E[j].second);
			}
		}
		
		set<int> s;
		for (int j = 0; j < n; j++) {
			if (uf.par[j] == j) {
				s.insert(uf.par[j]);
			}
		}
		if (sz(s) > 1) ans++;
	}

	out(ans);

	return 0;
}