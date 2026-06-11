#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class Abel> struct UnionFind {
  vector<int> par;
  vector<int> rank;
  vector<Abel> diff_weight;

  UnionFind(int n=1,Abel SUM_UNITY=0) {
    init(n, SUM_UNITY);
  }

  void init(int n=1,Abel SUM_UNITY=0) {
    par.resize(n); rank.resize(n); diff_weight.resize(n);
    for (int i=0;i<n;++i){
      par[i]=i;
      rank[i]=0;
      diff_weight[i]=SUM_UNITY;
    }
  }

  int root(int x) {
    if (par[x] == x) {
        return x;
    }
    else {
      int rx = root(par[x]);
      diff_weight[x] += diff_weight[par[x]];
      return par[x] = rx;
    }
  }

  Abel weight(int x) {
    root(x);
    return diff_weight[x];
  }

  bool same(int x,int y) {
    return root(x) == root(y);
  }

  bool unite(int x,int y,Abel w) {
    w+=weight(x);w-=weight(y);
    x=root(x);
    y=root(y);
    if (x == y){
      return false;
    }
    if (rank[x]<rank[y]){
      swap(x, y);
      w=-w;
    }
    if (rank[x] == rank[y]){
      ++rank[x];
    }
    par[y]=x;
    diff_weight[y]=w;
    return true;
  }

  Abel diff(int x, int y) {
    return weight(y)-weight(x);
  }
};

int main(){
  int N,M;
  cin >> N >> M;
  UnionFind<int> tree(N);
  bool ans=true;
  for (int i=0;i<M;i++){
    int L,R,D;
    cin >> L >> R >> D;
    if (!tree.same(L,R)){
      tree.unite(L,R,D);
    }
    else {
      if (tree.diff(L,R)!=D){
        ans=false;
        break;
      }
    }
  }
  if (ans){
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}