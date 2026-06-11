#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
#define ALL(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
 
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};



int main() {
  long long N, M; cin >> N >> M;
  UnionFind uf(N);
  vector<long long> A(M), B(M);
  REP(i, M) {
    int a, b; cin >> a >> b; a--; b--;
    A[i] = a;
    B[i] = b;
  }
  vector<long long> ans(100100, N * (N - 1) / 2);
  for (long long i = M - 1; i >= 0; i--) {
    int a = A[i], b = B[i];
    if (!uf.issame(a, b)) ans[i] = ans[i + 1] - uf.size(a) * uf.size(b);
    else ans[i] = ans[i + 1];
    uf.merge(a, b);
  }
  for(int i = 1; i <= M; i++) cout << ans[i] << endl;
  return 0;
}