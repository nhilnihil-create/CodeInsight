#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define dup(x,y) (((x)+(y)-1)/(y))
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const double EPS = 1e-10;
const int INF = 1e9;
const ll LINF = 1e15;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

typedef pair<ll, ll> pll;

struct UnionFind {
	vector<ll> par, siz;
	UnionFind(ll n): par(n), siz(n, 1) {
		rep(i,n) par[i] = i;
	}
	ll find(ll x) {
		if (par[x] == x) return x;
		else return par[x] = find(par[x]);
	}
	void unite(ll x, ll y) {
		x = find(x);
		y = find(y);
		if (x == y) return;
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		return;
	}
	bool is_same(ll x, ll y) {
		return find(x) == find(y);
	}
	ll size(int x) {
		return siz[find(x)];
	}
};

int main() {
	ll n, m;
	cin >> n >> m;
	vector<pll> v(m);
	rep(i,m) {
		cin >> v[i].first >> v[i].second;
		v[i].first--, v[i].second--;
	}
	reverse(ALL(v));
	UnionFind uf(n);
	vector<ll> ans(m);
	ans[0] = n * (n - 1) / 2;
	rep(i,m-1) {
		ll a = v[i].first;
		ll b = v[i].second;
		if (uf.is_same(a, b)) {
			ans[i+1] = ans[i];
			continue;
		}
		ll sub = uf.size(a) * uf.size(b);
		ans[i+1] = max(0ll, ans[i] - sub);
		uf.unite(a, b);
	}
	reverse(ALL(ans));
	rep(i,m) cout << ans[i] << endl;
}