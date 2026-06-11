#include<bits/stdc++.h>
using namespace std;
struct union_find{
  vector<int>parent;
  vector<int>rank;
  union_find(int n):parent(n),rank(n){
    for(int i=0;i<n;i++){
      parent[i]=i;
      rank[i]=0;
    }
  }
  int root(int x){
    return parent[x]==x?x:parent[x]=root(parent[x]);
  }
  bool same(int x,int y){
    return root(x)==root(y);
  }
  void uni(int x,int y){
    x=root(x);
    y=root(y);
    if(x==y)return;
    if(rank[x]>rank[y]){
      parent[y]=x;
    }else{
      parent[x]=y;
      if(rank[x]==rank[y]){
        rank[y]++;
      }
    }
  }

};

int main(){
  int N,M;
  cin>>N>>M;
  vector<pair<int,int>>data;
  for(int i=0;i<M;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    data.push_back(make_pair(a,b));
  }
  int cnt=0;
  int ans=0;
  for(int i=0;i<M;i++){
    union_find uf(N);
    for(int j=0;j<M;j++){
      if(i==j)continue;
      uf.uni(data[j].first,data[j].second);
    }
    int cnt=0;
    for(int j=0;j<N;j++)if(j==uf.root(j))cnt++;
    if(cnt>1)ans++;
  }
  cout<<ans<<endl;
}