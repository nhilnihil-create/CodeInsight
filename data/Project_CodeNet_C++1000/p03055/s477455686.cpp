#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
int main(){
int N;
  cin>>N;
  Graph G(N);
  for(int i=0;i<N-1;i++){
  int a,b; cin>>a>>b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }queue<int>que;
  vector<int>dist(N,-1);
  que.push(0);dist.at(0)=0;
  while(!que.empty()){
  int v=que.front();
    que.pop();
    for(auto u:G[v]){
    if(dist[u]!=-1)
      continue;
      else{
      dist[u]=dist[v]+1;
        que.push(u);
      }
    }
 }int Max=0;
    int a=-1;
    for(int i=0;i<N;i++){
    if(Max<dist[i]){Max=dist[i];a=i;}
    }queue<int>que1;
  vector<int>dist1(N,-1);dist1[a]=0;
  que1.push(a);
  while(!que1.empty()){
  int v=que1.front();
    que1.pop();
    for(auto u:G[v]){
    if(dist1[u]!=-1)
      continue;
      else{
      dist1[u]=dist1[v]+1;
        que1.push(u);
      }
    }
 }int ans=0;
  for(int i=0;i<N;i++)
    if(ans<dist1[i])
      ans=dist1[i];
  if(ans%3==1)
    cout<<"Second"<<endl;
  else
    cout<<"First"<<endl;
   return 0;
}

