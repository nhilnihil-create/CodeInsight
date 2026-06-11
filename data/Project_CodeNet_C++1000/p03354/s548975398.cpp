#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using namespace std;

const long long MOD = 1000000007;

// Ref. https://qiita.com/ofutonfuton/items/c17dfd33fc542c222396 //
struct UnionFind {
    vector<int> par;

    // Initialize. All vertices are roots when initial state.
    UnionFind(int N) : par(N) {
        REP(n,N) par.at(n) = n;
    }

    // Return the root of tree which consists of vertex(x)
    int root(int x) {
        if (par[x] == x) return x;     // If x is the root, return x
        return par[x] = root(par[x]);  // Recursively find the root of tree. 
    }

    // Unite two vertices into one tree. 
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[rx] = ry;
    }

    // Return true if two vertices has the same root, else return false.
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
};

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> pn(N);
  REP(n,N){
    int tmp;
    cin >> tmp;
    pn.at(n) = tmp - 1;
  }


  UnionFind tree(N); // initialize
  REP(m,M){
    int x, y;
    cin >> x >> y;
    tree.unite(x-1, y-1);
  }

  int ans = 0;
  REP(n,N){
    int num = pn.at(n);
    if(tree.same(n,num)) ans += 1;
  }
  cout << ans << endl;
}
