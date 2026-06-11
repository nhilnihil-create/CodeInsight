#include <bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define all(x) (x).begin(),(x).end()
#define PRINT(V) cout << V << "\n"
#define SORT(V) sort((V).begin(),(V).end())
#define RSORT(V) sort((V).rbegin(), (V).rend())
using namespace std;
using ll = long long;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1e10;
const ll MOD = 1000000007;
typedef pair<ll,ll> P;
template<class Abel> struct WeightedUnionFind {
    vector<ll> par;
    vector<ll> rank;
    vector<Abel> diff_weight;

    WeightedUnionFind(ll n = 1, Abel SUM_UNITY = 0) {
        init(n, SUM_UNITY);
    }

    void init(ll n = 1, Abel SUM_UNITY = 0) {
        par.resize(n); rank.resize(n); diff_weight.resize(n);
        for (ll i = 0; i < n; ++i) par[i] = i, rank[i] = 0, diff_weight[i] = SUM_UNITY;
    }

    ll root(ll x) {
        if (par[x] == x) {
            return x;
        }
        else {
            ll r = root(par[x]);
            diff_weight[x] += diff_weight[par[x]];
            return par[x] = r;
        }
    }

    Abel weight(ll x) {
        root(x);
        return diff_weight[x];
    }

    bool same(ll x, ll y) {
        return root(x) == root(y);
    }

    bool unite(ll x, ll y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        if (rank[x] == rank[y]) ++rank[x];
        par[y] = x;
        diff_weight[y] = w;
        return true;
    }

    Abel diff(ll x, ll y) {
        return weight(y) - weight(x);
    }
};
int main(){
    ll n,m;
    cin >> n >> m;
    WeightedUnionFind<int> a(n); 
    ll l,r,w;
    bool out = 0;
    rep(i,m){
        cin >> l >> r >> w;
        --l;--r;
        if (a.same(l,r)){
            if (a.diff(l,r) != w) out = 1;
        }
        else a.unite(l,r,w);
    }
    if (out) PRINT("No");
    else PRINT("Yes");
}