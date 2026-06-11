#include<bits/stdc++.h>
using namespace std;
struct Unionfind{
  vector<int>par;
  vector<int>rank;
  Unionfind(int n):par(n),rank(n){
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
  int N,M;
  cin>>N>>M;
  vector<pair<int,int>>edge(M);
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    edge[i].first=a;
    edge[i].second=b;
  }
  int cnt=0;
  for(int i=0;i<M;i++){
    //i番目の辺について調べる
    Unionfind uf(N);
    for(int j=0;j<M;j++){
      if(i!=j){
        int a=edge[j].first;
        int b=edge[j].second;
        uf.unit(a,b);
      }
    }
    int sa=edge[i].first;
    int sb=edge[i].second;
    
    if(!uf.same(sa,sb)){
      //cout<<"sa:"<<sa<<"sb:"<<sb<<endl;
      cnt++;
    }
  }
  cout<<cnt<<endl;
}