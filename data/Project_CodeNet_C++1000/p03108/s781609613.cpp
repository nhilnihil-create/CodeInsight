#include <bits/stdc++.h> 
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;

struct UnionFind
{
  vector<int> par;
  vector<int> sizes;

  UnionFind(int n) : par(n), sizes(n, 1) {
    rep(i,n) par[i] = i;
  }
  int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]); 
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (sizes[x] < sizes[y]) swap(x, y);
    par[y] = x;
    sizes[x] += sizes[y];
  }

  bool same(int x, int y) {
    return find(x) == find(y);
  }
  int size(int x) {
    return sizes[find(x)];
  }
};

int main(){
    ll n; cin>>n;
    ll m; cin>>m;
    UnionFind uf(n);
    int a[m],b[m];
    rep(i,m){
         cin>>a[i]>>b[i];
         a[i]--;b[i]--;
    }  
    
    ll ans[m+1]={0};
    for(int i=0;i<m;i++){
            if(uf.same(a[m-1-i],b[m-1-i])){
                ans[i+1]=ans[i];
            }
            else{
              ans[i+1]=ans[i]+uf.size(a[m-1-i])*uf.size(b[m-1-i]);
              uf.unite(a[m-1-i],b[m-1-i]);
            }
    }
    
    rep(i,m) cout<<n*(n-1)/2-ans[m-1-i]<<endl;
    
}