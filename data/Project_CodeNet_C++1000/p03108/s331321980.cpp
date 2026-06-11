#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

// Union-Find; 素集合データ構造
class UnionFind {
public:
    vector<long long> parent;
    long long n;
    UnionFind(long long x) :parent(x, -1), n(x){}
    bool unite(long long x, long long y){
        x = find(x); y = find(y);
        if (x == y) return false;
        if (size(x) < size(y)) swap(x, y);
        parent[x] += parent[y]; parent[y] = x;
        return true; }
    bool same(long long x, long long y){ return find(x) == find(y); }
    long long find(long long x){ return parent[x] < 0 ? x : parent[x] = find(parent[x]); }
    long long size(long long x){ return -parent[find(x)]; }
};

int main(){
    Init();
    ll n, m; cin >> n >> m;
    vi a(m), b(m);
    rep(i, m){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    UnionFind uf(n);
    vi ans(m);

    ll sz1 = 0, sz2 = 0;
    for(ll i=m-1; i>=0; i--){
        if(i == m-1) ans[i] = n*(n-1)/2;
        else ans[i] = ans[i+1]-sz1*sz2;
        if(uf.same(a[i], b[i])){
            sz1 = sz2 = 0;
        }
        else{
            sz1 = uf.size(a[i]);
            sz2 = uf.size(b[i]);
        }
        uf.unite(a[i], b[i]);
    }

    for(auto p: ans) cout << p << endl;
}