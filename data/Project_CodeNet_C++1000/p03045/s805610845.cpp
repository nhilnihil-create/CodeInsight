#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))
#define REPR(i, n) for(int (i) = (n); (i) >= 0; --(i))
#define FOR(i, n, m) for(int (i) = (n); (i) < (m); ++(i))

constexpr int INF = 1e9;
// constexpr ll INF = 1LL<<61;
constexpr ll mod = 1e9+7;

struct UnionFind {
  vector<int> data;
 
  UnionFind(int sz) {
    data.assign(sz, -1);
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
  
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  bool same(int a, int b){
    return find(a) == find(b);
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

int main(){
  int N, M;
  cin >> N >> M;
  vector<int> X(M), Y(M), Z(M);
  UnionFind uf(N);

  REP(i, M){
    cin >> X[i] >> Y[i] >> Z[i];
    X[i]--, Y[i]--;
    uf.unite(X[i], Y[i]);
  }
  int ans = 0;
  REP(i, N){
    if(uf.find(i) == i){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}