#include<bits/stdc++.h>
using namespace std;
struct UnionFind{
  vector<int> par;
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

  void Union(int x,int y){
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
  vector<int>Data(n);
  for(int i=0;i<n;i++){
    cin>>Data[i];
    Data[i]--;
  }
  UnionFind uf(n);
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    x--;y--;
    uf.Union(x,y);
  }
  int ans=0;
  for(int i=0;i<n;i++){
    if(uf.same(Data[i],i))ans++;
  }
  cout<<ans<<endl;
}