#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using vll = vector<ll> ;
#define all(v) v.begin(),v.end()

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};

int main(){
  ll N,M;cin>>N>>M;
  vll p(N);rep(i,N){cin>>p[i];p[i]--;}
  UnionFind uf(N);
  rep(i,M){
    int x,y;cin>>x>>y;x--,y--;
    uf.merge(x,y);
  }
  ll ans=0;
  rep(i,N){
    if(uf.issame(i,p[i]) || (i==p[i])) ans++;
  }
  cout << ans << endl;
}