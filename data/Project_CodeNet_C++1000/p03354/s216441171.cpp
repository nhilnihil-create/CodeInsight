#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(),x.end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
template<class T> inline bool chmax(T&a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T&a,T b){if(a>b){a=b;return 1;}return 0;}
using ll = long long;
using P = pair<int,int>;

int n,k,m,x,y;
string s,t;
int p[100005];

struct UnionFind {
  vector<int> par;
  UnionFind(int n=0): par(n,-1) {}
  int root(int x) {
    if (par[x] < 0) return x;
    return par[x] = root(par[x]);
  }
  bool unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return false;
    if (par[x] > par[y]) swap(x,y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y);}
  int size(int x) { return -par[root(x)];}
};

int main() {
  cin >> n >> m;
  rep(i,n) cin >> p[i], p[i]--;
  UnionFind uf(n);
  rep(i,m){
    cin >> x >> y;
    uf.unite(x-1,y-1);
  } 
  int ans=0;
  rep(i,n)if(uf.same(p[i],i)) ans++;
  cout << ans << endl;
}