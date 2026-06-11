#include<bits/stdc++.h>
using namespace std;
struct UnionFind{
  vector<int>par;
  vector<int>rank;
  UnionFind(int n):par(n),rank(n){
    for(int i=0;i<n;i++){
      par[i]=i;
      rank[i]=0;
    }
  }
  int root(int x){
    return par[x]==x?x:par[x]=root(par[x]);
  }
  bool same(int x,int y){
    return root(x)==root(y);
  }
  void unit(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)return;
    if(rank[x]<rank[y]){
      par[x]=y;
    }else{
      par[y]=x;
      if(rank[x]==rank[y]){
        rank[x]++;
      }
    }
  }
};
int main(){
  int n,m;
  cin>>n>>m;
  vector<pair<int,int>> edge(m);
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    edge[i].first=a;
    edge[i].second=b;
  }

  int cnt=0;
  int u1,u2,v1,v2;
  for(int i=0;i<m;i++){
     u1=edge[i].first;
     v1=edge[i].second;
    UnionFind uf(n);
    for(int j=0;j<m;j++){
      if(i!=j){
         u2=edge[j].first;
         v2=edge[j].second;
        uf.unit(u2,v2);
      }
    }
    if(!(uf.same(u1,v1)))cnt++;
  }
  cout<<cnt<<endl;
}