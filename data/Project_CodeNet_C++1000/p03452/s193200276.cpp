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
#define pb push_back
#define sz(x) ((int)(x).size())
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { ll g = gcd(a, b); return a / g * b; }
const int dx[4] = { 1, 0, -1,  0 };
const int dy[4] = { 0, 1,  0, -1 };
const int INF = (int)1e9;
const ll  inf = (ll)1e18;
const int mod = 1000000007;
const int MAX_N = 100010;

template<class Abel> struct UnionFind {
	vector<int> par;
	vector<int> rank;
	vector<Abel> diff_weight;

	UnionFind(int n = 1, Abel SUM_UNITY = 0) {
		init(n, SUM_UNITY);
	}

	void init(int n = 1, Abel SUM_UNITY = 0) {
		par.resize(n); rank.resize(n); diff_weight.resize(n);
		for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
	}

	int root(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			int r = root(par[x]);
			diff_weight[x] += diff_weight[par[x]];
			return par[x] = r;
		}
	}

	Abel weight(int x) {
		root(x);
		return diff_weight[x];
	}

	bool issame(int x, int y) {
		return root(x) == root(y);
	}

	bool merge(int x, int y, Abel w) {
		w += weight(x); w -= weight(y);
		x = root(x); y = root(y);
		if (x == y) return false;
		if (rank[x] < rank[y]) swap(x, y), w = -w;
		if (rank[x] == rank[y]) ++rank[x];
		par[y] = x;
		diff_weight[y] = w;
		return true;
	}

	Abel diff(int x, int y) {
		return weight(y) - weight(x);
	}
};

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	/*------------------------------*/

	int n, m;
	cin >> n >> m;

	UnionFind<int> uf(n);
	rep(i, m) {
		int l, r, d;
		cin >> l >> r >> d;
		l--; r--;
		if (uf.issame(l, r)) {
			int diff = uf.diff(l, r);
			if (diff != d) {
				out("No");
				return 0;
			}
		}
		else {
			uf.merge(l, r, d);
		}
	}

	out("Yes");

	return 0;
}