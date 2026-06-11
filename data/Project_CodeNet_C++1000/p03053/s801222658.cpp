#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
int main(){
int H,W;
  cin>>H>>W;
  vector<vector<char>>A(H,vector<char>(W));
  for(int i=0;i<H;i++){
  string s;
    cin>>s;
    for(int j=0;j<W;j++)
      A.at(i).at(j)=s.at(j);
  }Graph G(H*W);
  int sx[4]={-1,0,1,0};
  int sy[4]={0,-1,0,1};
  for(int i=0;i<H;i++){
  for(int j=0;j<W;j++){
    for(int k=0;k<4;k++){
    int X=i+sy[k]; int Y=j+sx[k];
      if(0<=X && X<=H-1 && 0<=Y && Y<=W-1)
        G[i*W+j].push_back(X*W+Y);
    }
  }
  }queue<int>que;
  vector<int>dist(H*W,-1);
  for(int i=0;i<H;i++){
  for(int j=0;j<W;j++){
   if(A.at(i).at(j)=='#'){
     que.push(W*i+j);
    dist.at(W*i+j)=0;
   }
  }
  }while(!que.empty()){
  int u=que.front();
    que.pop();
    for(auto v:G[u]){
    if(dist[v]!=-1)
      continue;
      else{
        dist[v]=dist[u]+1;
        que.push(v);
      }
    }
  
  }int ans=0;
  for(int i=0;i<H*W;i++)
    if(ans<dist[i])
      ans=dist[i];
  cout<<ans<<endl;
    return 0;
}
