#include <bits/stdc++.h>
#define r(i,n) for(int i = 0; i<n; i++)
typedef long long ll;
using namespace std;

struct UnionFind{
  vector<int> par;
  UnionFind(int N) : par(N){
    r(i,N)par[i]=i;
  }
  int root(int x){
    if(par[x]==x) return x;
    return par[x]=root(par[x]);
  }
  void unite(int x,int y){
    int rx=root(x);
    int ry=root(y);
    if(rx==ry) return;
    par[rx]=ry;
  }
  bool same(int x,int y){
    int rx=root(x);
    int ry=root(y);
    return rx==ry;
  }
};

int main() {
  int n,m,sum=0;
  cin >> n >> m;
  vector<int> v(n);
  r(i,n)cin >> v[i];
  
  UnionFind tree(n);
  r(i,m){
    int x,y;
    cin >> x >> y;
    tree.unite(x-1,y-1);
  }
  r(i,n){
    if(tree.same(i,v[i]-1))sum++;
  }
  cout<<sum<<endl;
}