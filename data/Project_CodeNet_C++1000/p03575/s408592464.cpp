#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define REP(i, n) for(ll i=0; i<(ll)(n); i++)
#define REPD(i, n) for(ll i=n-1; 0<=i; i--)
#define FOR(i, a, b) for(ll i=a; i<(ll)(b); i++)
#define FORD(i, a, b) for(ll i=a; (ll)(b)<=i; i--)
#define ALL(x) x.begin(), x.end()
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


struct UnionFind{
    vector<ll> par;
    UnionFind(ll n) : par(n, -1){}
    

    int root(int x){
        if(par[x]<0) return x;
        return par[x] = root(par[x]);
    }

    bool same(int a, int b){
        return root(a)==root(b);
    }
    void unite(int a, int b){
        int x=root(a), y=root(b);
        if(same(x, y)) return;
        if(y<x) swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }
    int size(int x){
        return -par[root(x)];
    }

};


int main(){
    int n, m;   cin >> n >> m;
    vector<pair<ll, ll>> g(m);
    REP(i, m){
        ll a, b;    cin >> a >> b;
        a--, b--;
        g[i] = {a, b};
    }
    ll res=m;
    REP(i, m){
        ll a=g[i].first, b=g[i].second;
        UnionFind tree = UnionFind(n);
        for(auto x: g){
            if(x.first==a && x.second==b) continue;
            tree.unite(x.first, x.second);
        }
        if(tree.same(a, b)) res -= 1;
    } 
    cout << res << endl;

}