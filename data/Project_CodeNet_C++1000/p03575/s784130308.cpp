#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i <(n); ++i)
#define REP2(i,x,n) for (int i = x; i <(n); ++i)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
static const double PI = acos(-1);
static const int INF = 1e9+7;


// UnionFind
//abc157_d で解説しているので参照する
// coding: https://youtu.be/TdR816rqc3s?t=726
// comment: https://youtu.be/TdR816rqc3s?t=6822
struct UnionFind {
vector<int> d;
UnionFind(int n=0): d(n,-1) {}
int find(int x) {
  if (d[x] < 0) return x;
  return d[x] = find(d[x]);
}
bool unite(int x, int y) {
  x = find(x); y = find(y);
  if (x == y) return false;
  if (d[x] > d[y]) swap(x,y);
  d[x] += d[y];
  d[y] = x;
  return true;
}
bool same(int x, int y) { return find(x) == find(y);}
int size(int x) { return -d[find(x)];}
};

int main(){
  int n, m;
  cin >> n >> m;

  vector<int> a(m);
  vector<int> b(m);


  REP(i,m){
    int ax, bx;
    cin >> ax >> bx;
    --ax; --bx;
    a[i] = ax;
    b[i] = bx;
  }

  int ans = 0;

  REP(i,m){
    UnionFind uf(n);
    REP(j,m){
      if(j == i) continue;
      uf.unite(a[j],b[j]);
    }
    if(!uf.same(a[i],b[i])) ans++;
  }

  cout << ans << endl;

  return 0;
}
