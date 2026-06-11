#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using ll=long long;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define MOD  1000000007
const ll INF=1e18;
template<class T>void show(vector<T>v){for (int i = 0; i < v.size(); i++){cerr<<v[i]<<" ";}cerr<<endl;}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b){ a = b; return 1; } return 0; }

struct UnionFind {
    vector<int> par;
    vector<int> sz;
 
    UnionFind(int n=0){ if(n>0) initialize(n); }
    void initialize(int n){
        par.resize(n);
        sz.assign(n, 1);
        for(int i=0; i<n; i++){
            par[i] = i;
        }
    }
 
    int find(int x){
        if(par[x] == x){
            return x;
        }else{
            return par[x] = find(par[x]);
        }
    }
 
    bool unite(int x, int y){
        x = find(x), y = find(y);
        if(x == y) return false;
        if(sz[x] > sz[y]) swap(x, y);
        par[x] = y;
        sz[y] += sz[x];
        return true;
    }
 
    bool same(int x, int y){ return find(x) == find(y); }
    int size(int x){ return sz[find(x)]; }
};

int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  int x, y;
  vector<int> p(n);
  rep(i, n) cin >> p[i];
  UnionFind uf(n);
  rep(i,m){
    cin >> x >> y;
    x--, y--;
    uf.unite(x, y);
  }
  int ans = 0;
  rep(i,n){
    if (uf.same(p[i]-1, i)) ans++;
  }
  cout << ans << endl;
  return 0;
}