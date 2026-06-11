#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;
    UnionFind(int N) : par(N) {
        for (int i=0; i<N; i++) par[i]=i;
    }
    int root(int x) {
        if (par[x]==x) return x;
        return par[x]=root(par[x]);
    }
    void unite(int x, int y) {
        int rx=root(x);
        int ry=root(y);
        if (rx==ry) return;
        par[rx]=ry;
    }
    bool same(int x,int y) {
        int rx=root(x);
        int ry=root(y);
        return rx==ry;
    }
};

int main() {
   int N,M;
   cin >> N >> M;
   int a[M],b[M];
   for (int i=0; i<M; i++) {
       int aa,bb;
       cin >> aa >> bb;
       a[i]=aa-1,b[i]=bb-1;
   }
   int count=0;
   for (int i=0; i<M; i++) {
       UnionFind tree(N);
       for (int j=0; j<M; j++) {
           if (i==j) continue;
           tree.unite(a[j],b[j]);
       }
       if (tree.same(a[i],b[i])) continue;
       count++;
   }
   cout << count << endl;
}