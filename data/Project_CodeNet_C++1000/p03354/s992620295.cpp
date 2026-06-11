#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UnionFind{
  vector<int> par;
  UnionFind(int N) : par(N){
    for(int i = 0; i < N; i++){
      par[i] = i;
    }
  }
  int root(int x){
    if(par[x] == x) return x;
    return par[x] = root(par[x]);
  }
  void unite(int x, int y){
    int rx = root(x);
    int ry = root(y);
    if(rx == ry) return;
    par[rx] = ry;
  }
  bool same(int x, int y){
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> P(N);
  for(int i = 0; i < N; i++) cin >> P[i];
  
  UnionFind tree(N);
  
  for(int i = 0; i < M; i++){
    int x, y;
    cin >> x >> y;
    tree.unite(x-1, y-1);
  }
  
  int cnt = 0;
  for(int i = 0; i < N; i++){
    if(tree.same(i, P[i]-1)){
      cnt++;
    }
    
  }
  cout << cnt << endl;
}