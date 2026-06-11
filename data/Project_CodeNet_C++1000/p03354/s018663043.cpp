#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using Pl = pair<ll,ll>;
#define REP(i,n) for(ll i = 0;i < (ll)n;i++)
#define REPD(i,n) for(ll i = (ll)n - 1;i >= 0;i--)
#define ALL(x) (x).begin(),(x).end()
#define FILLl(n,first_dimension_size,value) fill((ll*)n,(ll*)(n+first_dimension_size),value)
#define FILL(n,first_dimension_size,value) fill((int*)n,(int*)(n+first_dimension_size),value)
#define INF (1 << 29)
#define MOD 1000000007
//int dx[4] = {1,0,0,-1};
//int dy[4] = {0,1,-1,0};

class UnionFind{
  public:
  vector<int> par;
  UnionFind(int size) : par(size,-1){}
  bool unite(int x,int y){
    x = root(x),y = root(y);
    if(x == y)return false;
    if(par[y] < par[x])swap(x,y);
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
  int size(int x){
    return -par[root(x)];
  }
};

int main(){

  int n,m,res = 0;
  cin >> n >> m;
  vector<int> p(n);
  REP(i,n)cin >> p[i];
  UnionFind uf(n);
  REP(i,m){
    int x,y;cin >> x >> y;
    x--,y--;
    uf.unite(x,y);
  }
  REP(i,n){
    if(uf.find(i,p[i]-1))res++;
  }
  cout << res << endl;

  return 0;
}