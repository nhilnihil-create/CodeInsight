#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
using V = vector<ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
#define RALL(obj) (obj).rbegin(), (obj).rend()
#define MOD 1000000007
#define INF 1000000000

// union by size + path having
class UnionFind {
public:
	vector <ll> par; // 各元の親を表す配列
	vector <ll> siz; // 素集合のサイズを表す配列(1 で初期化)

	// Constructor
	UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
		for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
	}
	void init(ll sz_) {
		par.resize(sz_);
		siz.assign(sz_, 1LL);  // resize だとなぜか初期化されなかった
		for (ll i = 0; i < sz_; ++i) par[i] = i; // 初期では親は自分自身
	}

	// Member Function
	// Find
	ll root(ll x) { // 根の検索
		while (par[x] != x) {
			x = par[x] = par[par[x]]; // x の親の親を x の親とする
		}
		return x;
	}

	// Union(Unite, Merge)
	bool merge(ll x, ll y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		// merge technique（データ構造をマージするテク．小を大にくっつける）
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}

	bool issame(ll x, ll y) { // 連結判定
		return root(x) == root(y);
	}

	ll size(ll x) { // 素集合のサイズ
		return siz[root(x)];
	}
};

void solve_abc_e() {
	ll n, m, k;
	cin >> n >> m;
	ll ans = 0;

	V x(m), y(m), z(m);
	UnionFind uf(n);
	rep(i, m) {
		cin >> x[i] >> y[i] >> z[i];
		if (!uf.issame(x[i] - 1, y[i] - 1)) {
			uf.merge(x[i] - 1, y[i] - 1);
		}
	}

	unordered_map<ll, ll> um;
	rep(i, n) {
		um[uf.root(i)]++;
	}

	ans = um.size();

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc_e();

	return 0;
}