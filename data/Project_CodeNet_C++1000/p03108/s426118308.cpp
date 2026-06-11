#include<bits/stdc++.h>
#define int long long
using namespace std;
struct UnionFind{
  int par[100100],size[100100];
  UnionFind(int N){
    for(int i=0;i<N;i++)
      par[i]=i,size[i]=1;
  }
  int find(int x){
    if(par[x]==x)return x;
    int y=find(par[x]);
    par[x]=y;
    return y;
  }
  void unite(int x,int y){
    x=find(x),y=find(y);
    if(x==y)return;
    if(size[x]>=size[y])par[y]=x,size[x]+=size[y];
    else par[x]=y,size[y]+=size[x];
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
};
signed main(){
  int N,M;
  cin>>N>>M;
  vector<pair<int,int>> A(M);
  for(pair<int,int> &p:A){
    cin>>p.first>>p.second;
    p.first--,p.second--;
  }
  vector<int> B(M+1,N*(N-1)/2);
  UnionFind U(N);
  for(int i=M-1;i>=0;i--){
    pair<int,int> p=A[i];
    if(U.same(p.first,p.second))B[i]=B[i+1];
    else{
      B[i]=B[i+1]-U.size[U.find(p.first)]*U.size[U.find(p.second)];
      U.unite(p.first,p.second);
    }
  }
  for(int i=1;i<=M;i++)cout<<B[i]<<endl;
}