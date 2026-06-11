#include <bits/stdc++.h>
using namespace std;

template<class Abel> struct UnionFind {
    vector<int> p;
    vector<int> r;
    vector<Abel> dw;

    UnionFind(int n=1, Abel SUM_UNITY=0) {
        init(n, SUM_UNITY);
    }

    void init(int n=1, Abel SUM_UNITY=0) {
        p.resize(n);
        r.resize(n);
        dw.resize(n);
        for(int i=0; i<n; i++)
          p[i]=i, r[i]=0, dw[i]=SUM_UNITY;
    }

    int root(int x) {
        if(p[x] == x)
            return x;
        else {
            int r=root(p[x]);
            dw[x] += dw[p[x]];
            return p[x] = r;
        }
    }

    Abel weight(int x) {
        root(x);
        return dw[x];
    }

    bool issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y, Abel w) {
        w += weight(x); w -= weight(y);
        x = root(x); y = root(y);
        if(x == y)
          return false;
        if(r[x] < r[y])
          swap(x,y), w=-w;
        if(r[x] == r[y])
          ++r[x];
        p[y] = x;
        dw[y] = w;
        return true;
    }

    Abel diff(int x, int y) {
        return weight(y) - weight(x);
    }
};


int main() {
  int N,M,i,L,R,D;
  cin >> N >> M;
  UnionFind<int> uf(N);

  for(i=0; i<M; i++) {
    cin >> L >> R >> D;
    if(uf.issame(L-1,R-1) && uf.diff(L-1, R-1)!=D) {
      cout << "No" << endl;
      return 0;
    }
    uf.merge(L-1, R-1, D);
  }

  cout << "Yes" << endl;
}