#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

class UnionFind{
public:
    vector<ll> par;
    vector<ll> siz;

    UnionFind(ll k):par(k), siz(k, 1LL){
        rep(i,k) par[i] = i;
    }

    ll root(ll x){
        if(par[x]==x) return x;
        else return par[x] = root(par[x]);
    }

    void unite(ll x, ll y){
        x = root(x);
        y = root(y);
        if(x==y) return;

        if(siz[x]<siz[y]) swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return;
    }

    bool same(ll x, ll y){
        return root(x) == root(y);
    }

    ll size(ll x){
        return siz[root(x)];
    }
};

ll f(ll n){
	return n*(n-1)/2;
}

int main(){
	int n, m;
	cin >> n >> m;
	UnionFind uf(n);
	vector<P> bridge(m);
	rep(i,m) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		P p = make_pair(a, b);
		bridge[i] = p;
	}
	reverse(bridge.begin(), bridge.end());
	vector<ll> ans(m);
	rep(i,m) {
		int p = bridge[i].first;
		int q = bridge[i].second;
		ll s = f(uf.size(p));
		ll t = f(uf.size(q));
		if(!uf.same(p,q)){
			uf.unite(p,q);
			ll u = f(uf.size(p));
			ans[m-i-1] = u-s-t;
		}else{
			ans[m-1-i] = 0;
		}
	}
	ll now = 0;
	rep(i,m) {
		now += ans[i];
		cout << now << endl;
	}
}