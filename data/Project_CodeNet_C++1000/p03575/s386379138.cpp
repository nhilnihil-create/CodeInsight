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

vector<bool> seen;
vector<vector<ll>> g;
bool flag;
void dfs(int v=0, int p=-1){
    
    seen[v] = true;
    for(auto x: g[v]){
        if(x==p) continue;
        if(seen[x]) continue;
        dfs(x, v);
    }
}

int main(){
    int n, m;   cin >> n >> m;
    g.resize(n);
    vector<pair<ll, ll>> br(m);
    REP(i, m){
        ll a, b;    cin >> a >> b;
        a--, b--;
        g[a].push_back(b);
        g[b].push_back(a);
        br[i] = {a, b};
    }
    ll res=m;
    REP(i, m){
        seen.assign(n, false);
        ll a=br[i].first, b=br[i].second;
        flag=true;
        dfs(a, b);
        
        REP(j, n) if(!seen[j]) flag = false;
        if(flag) res -= 1;
        
    }
    cout << res << endl;
}