#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i) 
#define PI acos(-1)
#define pcnt __builtin_popcountll
#define rng(a) a.begin(), a.end()
#define sz(x) (int)(x).size()
#define v(T) vector<T>
#define vv(T) v(v(T))
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) {if (a > b) { a = b; return true; } return false; }

struct UnionFind {
    vl par;
    vl rank;
    
    UnionFind(ll n = 1) {
        init(n);
    }
    
    void init(ll n = 1) {
        par.resize(n); rank.resize(n);
        for (int i = 0; i < n; ++i) par[i] = i, rank[i] = 1;
    }
    
    int root(ll x) {
        if (par[x] == x) {
            return x;
        }
        else {
            ll r = root(par[x]);
            return par[x] = r;
        }
    }
    
    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }
    
    bool merge(ll x, ll y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        par[y] = x;
        rank[x] += rank[y];
        return true;
    }

    int getRank(ll i) {
        i = root(i);
        return rank[i];
    }
};

ll INF = 1001001001;
ll LINF = 1001001001001001001ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n, m;
    cin>>n>>m;
    vector<LP> ab(m);
    cin>>ab;
    rep(i, m) {
        ab[i].fi--;
        ab[i].se--;
    }

    vl ans(m + 1);
    ans.back() = n * (n - 1);
    UnionFind ds(n);
    for (int i = m - 1; i >= 0; --i) {
        if (!ds.issame(ab[i].fi, ab[i].se)) {
            ll r1 = ds.getRank(ab[i].fi);
            ll r2 = ds.getRank(ab[i].se);
            ds.merge(ab[i].fi, ab[i].se);
            ans[i] = ans[i + 1] - 2 * r1 * r2;
        }
        else ans[i] = ans[i + 1];
    }
    rep(i, m) {
        cout<<ans[i + 1] / 2<<endl;
    }
}