#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(pos,mp) for(ll pos=mp.begin();pos!=mp.end();pos -++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

//union find
struct UnionFind {
    vector<ll> parent;
    vector<ll> usize;
 
    UnionFind(int n) : parent(n), usize(n, 1LL){
        rep(i, n)parent[i]=i;
    }
    
    int root(int x){
        if(parent[x] == x) return x;
        else return parent[x] = root(parent[x]);
    }
    
    bool issame(int x, int y){
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
 
        if(x == y)return false;
 
        if(parent[x] > parent[y]) swap(x, y);

        usize[x] += usize[y];
        parent[y] = x;
 
        return true;
    }
    
    int size(int x) {
        return usize[root(x)];
    }
};

int main(){
    ll n, m;
    cin >> n >> m;

    UnionFind uf(n);
    rep(i, m){
        ll x, y, z;
        cin >> x >> y >> z;
        x--, y--;

        if(!uf.issame(x, y))uf.merge(x, y);
    }

    ll ans = 0;
    rep(i, n){
        if(i == uf.root(i))ans++;
    }

    cout << ans << endl;

}