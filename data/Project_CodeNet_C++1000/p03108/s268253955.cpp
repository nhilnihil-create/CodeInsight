#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> par;
    vector<int> siz;
    UnionFind(int N) : par(N),siz(N) {
        for (int i=0; i<N; i++) {
            par[i]=i,siz[i]=1;
        }
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
        siz[ry]+=siz[rx];
    }
    bool same(int x,int y) {
        int rx=root(x);
        int ry=root(y);
        return rx==ry;
    }
    int size (int x) {
        return siz[root(x)];
    }
};

int main() {
   long long N,M;
   cin >> N >> M;
   int A[M],B[M];
   for (int i=0; i<M; i++) {
       int a,b;
       cin >> a >> b;
       A[i]=a-1,B[i]=b-1;
   }
   long long total[M];
   UnionFind tree(N);
   for (int i=0; i<M; i++) {
       if (i==0) {
           total[M-1]=N*(N-1)/2;
       }
       else {
           if (tree.same(A[M-i],B[M-i])) total[M-1-i]=total[M-i];
           else {
               long long a=tree.size(A[M-i]),b=tree.size(B[M-i]);
               total[M-i-1]=total[M-i]-a*b;
               tree.unite(A[M-i],B[M-i]);
           }
       }
   }
   for (int i=0; i<M; i++) cout << total[i] << endl;
}