#include<bits/stdc++.h>
using namespace std;
struct edge{
int to,d;
};
using Graph=vector<vector<edge>>;
int main(){
int N;
  cin>>N;
  Graph G(N);
  for(int i=0;i<N-1;i++){
  int u,v,w;
    cin>>u>>v>>w;u--; v--;
    edge e={v,w};
    G[u].push_back(e);
    edge E={u,w};
    G[v].push_back(E);
  }queue<int>que;
  que.push(0);
  vector<int>color(N,-1);
  color.at(0)=0;
  while(!que.empty()){
  int v=que.front();
    que.pop();
    for(auto e:G[v]){
    if(color.at(e.to)!=-1)
      continue;
      else{
      if(color.at(v)==1){
      if(e.d%2==0)
        color.at(e.to)=1;
        else
          color.at(e.to)=0;
      }else{
      if(e.d%2==0)
        color.at(e.to)=0;
        else
          color.at(e.to)=1;
      } que.push(e.to);
      
      }
    
    }
  
  }for(int i=0;i<N;i++)
    cout<<color.at(i)<<endl;
   return 0;
}