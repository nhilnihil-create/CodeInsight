#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

struct UnionFind {
  vector<int> d;
  UnionFind(int n): d(n, -1){}
  int find (int x) {
    if(d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite (int x, int y){
    x = find(x), y = find(y);
    if(x == y) return false;
    if(d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  bool size(int x) { return -d[find(x)]; }
};

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  UnionFind uf(n);
  rep(i, n) {
    int x;
    cin >> x;
    --x;
    p[i] = x;
  }
  rep(i, m){
    int x, y;
    cin >> x >> y;
    --x; --y;
    uf.unite(x, y);
  }
  ll ans = n;
  rep(i, n){
    if(!uf.same(p[i], i)) ans--;
  }
  cout << ans << endl;
}