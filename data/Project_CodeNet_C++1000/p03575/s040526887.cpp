#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
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
    ll n, m, cnt = 0; cin >> n >> m;
    vector<pair<ll, ll>> edge(m);
    rep(i, m) cin >> edge[i].first >> edge[i].second;

    // i番目のエッジを除いてUnionFindを作り、要素数の差異で非連結か判断
    rep(i, m){
        UnionFind uf(n);
        rep(j, m){
            if(j == i) continue;
            ll v1 = edge[j].first-1;
            ll v2 = edge[j].second-1;
            uf.unite(v1, v2);
        }
        if(uf.size(0) != n) cnt++;
    }
    cout << cnt << endl;
}