#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const long long MOD = 1000000007;

// Ref.[1] https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396 //
// Ref.[2] https://atcoder.jp/contests/abc120/submissions/4444370 //
class UnionFind {
    vector<int> par,sz;
  public:

    // Initialize. All vertices are roots when initial state.
    UnionFind(int N) : par(N),sz(N) {
      REP(n,N){
        par[n] = n;
        sz[n] = 1;
      }
    }

    // Return the root of tree which consists of vertex(x)
    int root(int x) {
      if (par[x] == x) return x;     // If x is the root, return x
      return par[x] = root(par[x]);  // Recursively find the root of tree. 
    }

    // Unite two vertices into one tree. 
    void unite(int x, int y) {
      int rx = root(x);       // root of x
      int ry = root(y);       // root of y
      if (rx == ry) return;   // do nothing if root of x is the same as root of y
      if(sz[rx] > sz[ry]){
        par[ry] = rx;
        sz[rx] += sz[ry];
      }else{
        par[rx] = ry;
        sz[ry] += sz[rx];
      }
    }

    // Return true if two vertices has the same root, else return false.
    bool same(int x, int y) { return root(x) == root(y); }

    // Return the number of vertices which are component of a tree
    int size(int x){ return sz[root(x)]; }
};

int main() {
  int N, M;
  cin >> N >> M;


  vector<int> A(M);
  vector<int> B(M);

  REP(m,M){
    int a, b;
    cin >> a >> b;
    A[m] = a-1, B[m] = b-1;
  }

  UnionFind tree(N);

  long long inconv = N*(long long)(N-1)/2;
  vector<long long> res;
  
  RREP(m,M){
    res.push_back(inconv);
    if (tree.same(A[m],B[m])) continue;

    inconv -= tree.size(A[m])*tree.size(B[m]);
    tree.unite(A[m],B[m]);

  }
  reverse(res.begin(),res.end());
  REP(m,M) cout << res.at(m) << endl;
}
