#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<long long int> par;
  
  UnionFind(long long int N) {
    par = vector<long long int>(N, (long long int)-1);
  }
  
  long long int root(long long int x) {
    if (par.at(x) < 0) return x;
    return par.at(x) = root(par.at(x));
  }
  
  bool unite(long long int x, long long int y) {
    long long int rx = root(x);
    long long int ry = root(y);
    if (rx == ry) return false;
    if (par.at(rx) > par.at(ry)) swap(rx, ry);
    par.at(rx) += par.at(ry);
    par.at(ry) = rx;
    return true;
  }
  
  bool same(long long int x, long long int y) {
    long long int rx = root(x);
    long long int ry = root(y);
    return rx == ry;
  }
  
  int size(int x) {
    return -par.at(root(x));
  }
};

int main() {
  long long int N, M;
  cin >> N >> M;
  vector<long long int> A(M), B(M), ans(M, N * (N - 1) / 2);
  for (long long int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
    A.at(i)--;
    B.at(i)--;
  }
  UnionFind tree(N);
  for (long long int i = M - 1; i >= 0; i--) {
    if (i > 0 && !(tree.same(A.at(i), B.at(i)))) {
      ans.at(i - 1) = ans.at(i) - tree.size(A.at(i)) * tree.size(B.at(i));
    }
    else if (i > 0) ans.at(i - 1) = ans.at(i);
    tree.unite(A.at(i), B.at(i));
  }
  for (long long int i = 0; i < M; i++) cout << ans.at(i) << endl;
}