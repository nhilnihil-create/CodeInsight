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
  vector<int> a(m), b(m);
  rep(i, m){
    int s, t; cin >> s >> t;
    a[i] = s - 1;
    b[i] = t - 1;
  }
  DisjointSet ds = DisjointSet(n);
  vector<ll> ans(m+1);
  ans[m] = ((ll)n * (n - 1)) / 2;
  for(int i = m - 1; i >= 0; i--){
    int x = a[i], y = b[i];
    if(ds.same(x, y)){
      ans[i] = ans[i + 1];
      continue;
    }
    ll sizex = ds.getSize(x), sizey = ds.getSize(y);
    //cout << x << " " << y << " : ";
    //cout << sizex << " " << sizey << endl;
    ds.unite(x, y);
    ans[i] = max(ans[i + 1] - sizex * sizey, 0LL);
  }
  rep(i, m){
    cout << ans[i+1] << endl;
  }
  return 0;
}
