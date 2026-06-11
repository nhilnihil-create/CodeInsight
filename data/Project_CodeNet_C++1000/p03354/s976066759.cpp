#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
using P = pair<ll, ll>;
#define rep(i, n) for(ll i=0;i<(ll)(n);i++)
#define rep1(i, n) for(ll i=1;i<=(ll)(n);i++)
#define rep2(i, m, n) for(ll i=m;i<(ll)(n);i++)
#define rrep(i, n, m) for(ll i=n;i>=(ll)(m);i--)
#define ALL(obj) (obj).begin(), (obj).end()
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

void solve_abc098() {
	ll N, M;
	cin >> N >> M;

	// スワップグループをつくっていく
	// グループ内では自由に順番を決めれる
	// グループはくっつくことがあるので、UnionFind
	// 最終的にグループごとに、数列の順番ごとに一致できるかどうか、数え上げていく
	// グループごとの一致数の和がans

	vector<ll> p(N);
	rep(i, N) {
		cin >> p[i];
	}

	UnionFind uf(N+1);

	ll x, y;

	rep(i, M) {
		cin >> x >> y;
		uf.merge(x, y);
	}

	ll ans = 0;

	rep(i, N) {
		if (uf.issame(i + 1, p[i])) {
			ans++;
		}
	}

	cout << ans << "\n";
}

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	solve_abc098();

	return 0;
}
