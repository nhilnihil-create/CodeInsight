#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct UnionFind {
  vector<int> r;
  
  UnionFind(int N) {
    r = vector<int>(N, -1);
    
  }
  
  int root(int x) {
    if (r[x] < 0) return x;
    return r[x] = root(r[x]);
  }
  
  
  bool unite(int x, int y) {
    x = root(x);
    y = root(y);
    
    if (x == y) return false;
    if (r[x] > r[y]) swap(x, y);
    
    r[x] += r[y];
    r[y] = x;
    
    return true;
  }
  
  int size(int x) {
    return -r[root(x)];
  }
  
};


int main() {
  ll N, M;
  cin >> N >> M;
  
  vector<pair<int, int>> bridge(M);
  
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    
    bridge[i] = {a, b};
  }
  
  vector<ll> ans(M+1);
  
  UnionFind UF(N);

  ll temp = N * (N-1)/2;
  ans[M] = temp;
  
  for (int i = M-1; i >= 0; i--) {
    
    int A = bridge[i].first, B = bridge[i].second;
    A--; B--;
    
    if (UF.root(A) != UF.root(B)) {
      temp -= (ll)UF.size(A) * (ll)UF.size(B);
    }  
    ans[i] = temp;
    
    
    UF.unite(A, B);
    
  }
  
  for (int i = 1; i <= M; i++) {
    cout << ans[i] << endl;
  } 
  
}