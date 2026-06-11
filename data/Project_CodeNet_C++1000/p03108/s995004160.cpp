#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

class UnionFind {
public:
	vector < ll > par;
	vector < ll > siz;
	UnionFind(ll sz_) : par(sz_), siz(sz_, 1) {
		for (ll i = 0; i < sz_; ++i) par[i] = i;
	}
	void init(ll sz_) {
		par.resize(sz_);
		siz.assign(sz_, 1);
		for (ll i = 0; i < sz_; ++i) par[i] = i;
	}
	ll root(ll x) {
		while (par[x] != x) {
			x = par[x] = par[par[x]];
		}
		return x;
	}
	bool unite(ll x, ll y) {
		x = root(x);
		y = root(y);
		if (x == y) return false;
		if (siz[x] < siz[y]) swap(x, y);
		siz[x] += siz[y];
		par[y] = x;
		return true;
	}
	bool same(ll x, ll y) {
		return root(x) == root(y);
	}
	ll size(ll x) {
		return siz[root(x)];
	}
};

int main() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m), ans(m);
    UnionFind UF(n);
    rep(i, m)cin >> a[i] >> b[i];
    reverse(all(a));
    reverse(all(b));
    ans[0] = n * (n-1) / 2;
    REP(i, m-1){
        int A = a[i-1]-1, B = b[i-1]-1;
        if(!UF.same(A, B)){
            ans[i] = ans[i-1]-UF.size(A)*UF.size(B);
        }
        else ans[i] = ans[i-1];
        UF.unite(A, B);
    } 
    reverse(all(ans));
    rep(i, m)cout << ans[i] << endl;
}
