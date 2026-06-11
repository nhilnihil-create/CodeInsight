#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007

class UnionFind{
  public:
  vector<int> par;
  UnionFind(int n) : par(n,-1) {}
  bool unite(int x,int y){
    x = root(x),y = root(y);
    if(x == y)return false;
    if(par[x] > par[y])swap(x,y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }
  bool find(int x,int y){
    return root(x) == root(y);
  }
  int root(int x){
    return par[x] < 0 ? x : par[x] = root(par[x]);
  }
};

int main(){

  int n,m;
  cin >> n >> m;
  UnionFind uf(n);
  rep(i,m){
    int x,y,z;cin >> x >> y >> z;
    x--,y--;
    uf.unite(x,y);
  }
  int res = 0;
  rep(i,n)if(uf.root(i) == i)res++;
  cout << res << endl;
  



  return 0;
}