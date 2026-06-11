#include<iostream>
#include<vector>
using namespace std;

struct UnionFind {
  vector<int> r;

  UnionFind(int N) {
    r = vector<int>(N, -1);
  }

  int getRoot(int x) {
    if (r[x] < 0) return x;
    return r[x] = getRoot(r[x]);
  }

  /**
   * 指定の2頂点が属する木が同じか
   */
  bool belongTo(int x, int y) {
    int rx = getRoot(x);
    int ry = getRoot(y);
    return rx == ry;
  }

  void unite(int x, int y) {
    int rx = getRoot(x);
    int ry = getRoot(y);
    if (rx == ry) return;

    r[rx] += r[ry];
    r[ry] = rx;
  }

  int size(int x) {
    return -r[getRoot(x)];
  }
};

int main() {
  int N,M,x,y,i,ans=0;
  cin>>N>>M;
  UnionFind UF(N);
  vector<int> p(N);
  for (i=0;i<N;i++) cin>>p[i];
  for (i=0;i<M;i++) {
    cin>>x>>y;
    UF.unite(x-1, y-1);
  }
  for (i=0;i<N;i++) {
    if (p[i]-1 == i || UF.belongTo(i,p[i]-1)) ans++;
  }
  cout<<ans<<endl;
  return 0;
}
