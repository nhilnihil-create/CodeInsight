#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(ll itr=mp.begin();itr!=mp.end();itr -++)
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

    ll a[m], b[m];
    rep(i, m){
        cin >> a[m-i-1] >> b[m-i-1]; 
        a[m-i-1]--, b[m-i-1]--;
    }

    UnionFind uf(n);
    ll cnt[m];
    rep(i, m){
        if(!uf.issame(a[i], b[i])){
            cnt[i] = uf.size(a[i]) * uf.size(b[i]);
            uf.merge(a[i], b[i]);
        }
        else {
            cnt[i] = 0;
        }
    }

    ll ans = 0;
    rep(i, m){
        ans += cnt[m-i-1];
        cout << ans << endl;
    }
}