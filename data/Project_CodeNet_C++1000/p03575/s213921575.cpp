#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  
  vector<int> r;
  
  UnionFind(int N) {
    r = vector<int>(N, -1); // 初期化
  }
  
  
  // 根を返す(経路圧縮つき)
  int root(int x) {
    if (r[x] < 0) return x;
    return r[x] = root(r[x]); // 圧縮
  }
  
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    
    if (x == y) return false;
    if (r[x] > r[y]) swap(x, y);
    
    // xが親になるように合併した
    r[x] += r[y]; // xは親なので頂点数 * (-1）を更新
    r[y] = x; // y は親ではないので親であるxをさす
    return true;
  }
  
  int size(int x) {
    return -r[root(x)];
  }


};

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<pair<int,int>> edge(M);
  
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    
    edge[i] = {a, b};
  }
  
  int ans = 0;
  
  // i番目の辺を抜いて，UnionFindを作り，1のsizeを調べてNと一致するか
  for (int i = 0; i < M; i++) {
    
    
    // UnionFindの作成
    UnionFind UF(N);
    
    for (int j = 0; j < M; j++) {
      // i番目の辺を無視
      if (j == i) continue;
      
      int A = edge[j].first, B = edge[j].second;
      A -= 1; B -= 1;
      
      UF.unite(A, B);
      
    }
    
    
    
    // UnionFind が1つのグループからなるか
    if (UF.size(1) != N) ans++;
  }
    
  cout << ans << endl;
  
  
  
}