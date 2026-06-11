#include<bits/stdc++.h>
#define int long long
using namespace std;
struct UnionFind{
  vector<int> par,rank;
  UnionFind(int N){
    for(int i=0;i<N;i++){
      par.push_back(i);
      rank.push_back(1);
    }
  }
  int find(int x){
    if(par[x]==x)
      return x;
    else{
      int y=find(par[x]);
      par[x]=y;
      return y;
    }
  }
  void unite(int x,int y){
    int x2=find(x),y2=find(y);
    if(rank[x2]>=rank[y2])
      par[y2]=x2,rank[x2]=max(rank[x2],rank[y2]+1);
    else
      par[x2]=y2;
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
};
signed main(){
  int N,M;
  cin>>N>>M;
  vector<int> A(N);
  for(int &i:A){
    cin>>i;
    i--;
  }
  UnionFind B(N);
  for(int i=0;i<M;i++){
    int x,y;
    cin>>x>>y;
    B.unite(x-1,y-1);
  }
  int ans=0;
  for(int i=0;i<N;i++)
    if(B.same(i,A[i]))
      ans++;
  cout<<ans<<endl;
  return 0;
}