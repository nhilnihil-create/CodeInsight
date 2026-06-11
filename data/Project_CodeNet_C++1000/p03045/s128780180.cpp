#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i < int(n); i++)

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
    int n,m;cin>>n>>m;
    UnionFind u(n);
    rep(i,m){
        int x,y,z;
        cin>>x>>y>>z;
        x--;y--;
        u.unite(x,y);
    }
    set<int>ans;
    rep(i,n){
        ans.insert(u.find(i));
    }
    cout<<ans.size()<<endl;
}