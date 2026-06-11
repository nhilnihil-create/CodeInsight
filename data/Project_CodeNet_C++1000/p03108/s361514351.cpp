#include <bits/stdc++.h>
using namespace std;
struct UF {
  vector<long> pare, rank, mass;
  UF(long n) : pare(n), rank(n), mass(n){
    for(long i=0; i<n; i++){ pare[i]=i; rank[i]=0; mass[i]=1; }
  }
  long root(long x){ return (pare[x]==x)?x:pare[x]=root(pare[x]); }
  bool same(long x, long y){ return root(x)==root(y); }
  void marg(long x, long y){
    x=root(x); y=root(y); if(x==y) return;
    if(rank[x]<rank[y]){ pare[x]=y; }
    else{ pare[y]=x; if(rank[x]==rank[y]){rank[x]++;} }
    mass[x]=mass[y]=mass[x]+mass[y];
  }
  long weit(long x){ return mass[root(x)]; }
};

int main(){
long N, M, i; cin >> N >> M;
long A[M], B[M], ans[M]; ans[M-1]=N*(N-1)/2; 
for(i=0; i<M; i++){ cin >> A[i] >> B[i]; A[i]--; B[i]--; }
UF G(N);
for(i=M-1; i>0; i--){ 
  if(G.same(A[i], B[i])){ ans[i-1]=ans[i]; }
  else{ ans[i-1]=ans[i]-G.weit(A[i])*G.weit(B[i]); }
  G.marg(A[i], B[i]);
}
for(i=0; i<M; i++){ cout << ans[i] << " "; }
cout << "\n"; return 0;
}