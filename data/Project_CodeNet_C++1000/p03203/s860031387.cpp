#include<bits/stdc++.h>
using namespace std;
int H,W,N;
int main(){
  cin>>W>>H>>N;
  vector<vector<int>>G(H+1);
  vector<set<int>>A(H+1);
  for(int i=0;i<=H;i++){
  G[i].push_back(W);
    A[i].insert(W);
  }for(int i=0;i<N;i++){
  int x,y;cin>>x>>y;x--;y--;
    G[y].push_back(x);
    A[y].insert(x);
  }for(int i=0;i<H;i++)
    sort(G[i].begin(),G[i].end());
  int a=0;int ans=W;
  for(int i=0;i<H;i++){
  auto itr=upper_bound(G[i].begin(),G[i].end(),a);
    int k=distance(G[i].begin(),itr);if(G[i][k]<ans)ans=G[i][k];
    bool x=false;int b=a;
    for(int j=b+1;j<G[i][k];j++)
      if(!A[i+1].count(j)){a=j;x=true;break;}
    if(!x || ans<a)
      break;
    }cout<<ans<<endl;
  return 0;
}