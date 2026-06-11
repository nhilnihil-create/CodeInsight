#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
#define rep(i,s,e) for(int (i) = (s);(i) <= (e);(i)++)

#include <vector>
using namespace std;
using i64 = long long;

struct WeightedUnionFind {
  vector<int> par;
  vector<i64> ws;

  WeightedUnionFind(int n) : par(n, 0), ws(n, 0) {
    for (int i = 0; i < n; i++) {
      par[i] = -1;
    }
  }

  int find(int x) {
    if (par[x] < 0) {
      return x;
    } else {
      const int parent = find(par[x]);
      ws[x] += ws[par[x]];
      return par[x] = parent;
    }
  }

  int weight(int x) {
    find(x);
    return ws[x];
  }

  bool unite(int x, int y, int w)  // x + w = y
  {
    w += weight(x);
    w -= weight(y);
    x = find(x);
    y = find(y);

    if (x != y) {
      if (par[y] < par[x]) {
        swap(x, y);
        w = -w;
      }
      par[x] += par[y];
      par[y] = x;
      ws[y] = w;
      return true;
    } else {
      return false;
    }
  }

  bool same(int x, int y) { return find(x) == find(y); }

  pair<bool, int> diff(int x, int y) {
    if (!same(x, y)) return {false, 0};
    return {true, weight(x) - weight(y)};
  }
};

int N;
int M;

int main(){
  cin >> N;
  cin >> M;

  WeightedUnionFind uf(N);
  
  rep(i,0,M - 1){
    int l,r,d;
    cin >> l >> r >> d;
    l--;
    r--;
    auto p = uf.diff(r,l);
    if(!p.first){
      uf.unite(l,r,d);
    }
    else if(p.second != d){
      cout << "No" << endl;
      return 0;
    }
  }

  cout << "Yes" << endl;
}
