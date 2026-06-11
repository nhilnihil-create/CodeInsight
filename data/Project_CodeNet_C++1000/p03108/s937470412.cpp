#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

using namespace std;

static const ll INF = 1e15;

template<typename T>
static inline void chmin(T & ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T & ref, const T value) {
    if (ref < value) ref = value;
}

const ll mod = 1000000007;

struct UnionFind {
public:
	vector <ll> par; // 
	vector <ll> siz; // 

	ll answer;

	UnionFind() {}

	UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
		for (ll i = 0; i < sz_; ++i) par[i] = i;
		answer = sz_ * (sz_ - 1) / 2;
	}
	void init(ll sz_) {
		par.resize(sz_);
		siz.assign(sz_, 1LL);
		for (ll i = 0; i < sz_; ++i) par[i] = i;
		answer = sz_ * (sz_ - 1) / 2;
	}

	ll root(ll x) {
		while (par[x] != x) {
			x = par[x] = par[par[x]];
		}
		return x;
	}

	bool merge(ll x, ll y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (siz[x] < siz[y]) swap(x, y);
		answer -= (siz[x] * siz[y]);
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}

	ll query() const {
		return answer;
	}

	bool issame(ll x, ll y) {
		return root(x) == root(y);
	}

	ll size(ll x) {
		return siz[root(x)];
	}
};

int main() {
	ll n, m;
	cin >> n >> m;
	vector<P> edges(m);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		edges[i] = { a,b };
	}
	vector<ll> ans(m);
	UnionFind uf(n);
	for (int i = m - 1; i >= 0; i--) {
		ans[i] = uf.query();
		uf.merge(edges[i].first, edges[i].second);
	}
	for (auto a : ans) {
		cout << a << endl;
	}
	return 0;
}

