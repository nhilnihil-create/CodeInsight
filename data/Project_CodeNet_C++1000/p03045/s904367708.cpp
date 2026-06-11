#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define pb push_back
using namespace std;
typedef long long ll;

int n,m;

struct UnionFind{
  vector<int> par;
  UnionFind(int n):par(n){
    rep(i,n) par[i]=i;
  }
  int root(int x){
    if(par[x]==x) return x;
    return par[x]=root(par[x]);
  }
  void unite(int x,int y){
    if(root(x)==root(y)) return;
    par[root(x)]=root(y);
  }
  bool same(int x,int y){
    return root(x)==root(y);
  }
};

int main(){
  cin>>n>>m;
  vector<int> a(n);
  
  UnionFind tree(n);
  rep(i,m){
    int x,y,z;
    cin>>x>>y>>z;
    x--; y--;
    tree.unite(x,y);
  }
  int res=0;
  vector<int> seen(n);
  rep(i,n){
    if(seen[tree.root(i)]!=0) continue;
    seen[tree.root(i)]=1;
    res++;
  }
  cout<<res<<endl;
}