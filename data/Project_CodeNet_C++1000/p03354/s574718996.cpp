#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

class DisjointSet{
public:
  vector<int> rank, p, sz;

  DisjointSet(){}
  DisjointSet(int size){
    rank.resize(size, 0);
    p.resize(size, 0);
    sz.resize(size, 0);
    rep(i, size) makeSet(i);
  }

  void makeSet(int x){
    p[x] = x;
    rank[x] = 0;
    sz[x] = 1;
  }

  bool same(int x, int y){
    return findSet(x) == findSet(y);
  }

  void unite(int x, int y){
    link(findSet(x), findSet(y));
  }

  void link(int x, int y){
    if(rank[x] > rank[y]){
      p[y] = x;
      sz[x] += sz[y];
    }
    else{
      p[x] = y;
      sz[y] += sz[x];
      if(rank[x] == rank[y]){
        rank[y]++;
      }
    }
  }

  int findSet(int x){
    if(x != p[x]){
      p[x] = findSet(p[x]);
    }
    return p[x];
  }

  int getSize(int x){
    return sz[findSet(x)];
  }
};


int main(){
  int n, m; cin >> n >> m;
  vector<int> p(n), id(n);
  rep(i, n){
    cin >> p[i];
    p[i]--;
    id[p[i]] = i;
  }
  vector<int> a(m), b(m);
  DisjointSet ds = DisjointSet(n);
  rep(i, m){
    int s, t; cin >> s >> t;
    a[i] = s - 1;
    b[i] = t - 1;
    ds.unite(a[i], b[i]);
  }


  int ans = 0;
  rep(i, n){
    if(ds.same(p[i], id[p[i]])){
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
