#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;

struct UnionFind{
  vector<int> par;
  vector<int> siz;

  UnionFind(int N){
    par.resize(N);siz.resize(N);
    for(int i=0;i<N;i++) par[i]=i;
    for(int i=0;i<N;i++) siz[i]=1;
  }

  int root(int x){
    if(par[x]==x) return x;
    else return par[x]=root(par[x]);
  }

  bool unite(int x,int y){
    int rx=root(x);
    int ry=root(y);
    if (rx == ry) return false;
    if(siz[rx] < siz[ry]) swap(rx,ry);
    siz[rx] += siz[ry];
    par[ry] = rx;
    return true;
  }

  bool sameroot(int x,int y){
    return root(x)==root(y);
  }
  
  int size(int x){
    return siz[root(x)];
  }
};

int main(){
  int N,M;
  cin>>N>>M;
  UnionFind u(N);
  vector<int> A(M),B(M);
  for(int i(0);i<M;i++){
    cin>>A[i]>>B[i];
    A[i]--;B[i]--;
  }

  vector<ll> ans;
  ll cnt(0);
  for(int i(M-1);i>=0;i--){
    ans.push_back(cnt);
    if (!u.sameroot(A[i],B[i])){
      if(u.size(A[i]) != 1 && u.size(B[i]) != 1){
        cnt += (ll)u.size(A[i])*u.size(B[i]);
        u.unite(A[i],B[i]);
      }else{
        u.unite(A[i],B[i]);
        cnt += (u.size(A[i])-1);
      }
    }
  }
  ll tmp(N*(ll)(N-1)/2);
  for(int i(0);i<M;i++){
    cout << tmp - ans[M - i - 1] << endl;
  }
  return 0;
}
