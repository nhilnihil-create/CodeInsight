#include <bits/stdc++.h>
using namespace std;
struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) : par(n, -1) { }
    void init(int n) { par.assign(n, -1); }
    
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
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
};
int main() {
  int N,M;cin>>N>>M;
  vector<int>V(N);
  UnionFind UF(N);
  for(int X=0;X<N;X++){
    cin>>V[X];V[X]--;
  }
  for(int X=0;X<M;X++){
    int A,B;cin>>A>>B;A--;B--;
    UF.merge(A,B);
  }
  int H=0;
  for(int X=0;X<N;X++){
    if(UF.issame(X,V[X]))H++;
  }
  cout<<H<<endl;
}
