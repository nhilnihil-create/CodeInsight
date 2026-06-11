#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,u,v,w;
  cin>>N;
  vector<pair<int,int>>G[N];
  int C[N];
  for(int i=0;i<N;i++){
    C[i]=-1;
  }
 
  for(int i=0;i<N-1;i++){
    cin>>u>>v>>w;
    u--;
    v--;
    G[u].push_back({v,w});
    G[v].push_back({u,w});
  }

  queue<int>que;
  C[0]=0;
  que.push(0);
  while(!que.empty()){
    int i=que.front();
    que.pop();
    for(int j=0;j<G[i].size();j++){
      if(C[G[i].at(j).first]==-1 && (G[i].at(j).second)%2==0){
        C[G[i].at(j).first]=C[i];
        que.push(G[i].at(j).first);
      }
      else if(G[i].at(j).second%2!=0){
        if(C[G[i].at(j).first]==-1 && C[i]==0){
          C[G[i].at(j).first]=1;
          que.push(G[i].at(j).first);
        }
        else if(C[G[i].at(j).first]==-1 && C[i]==1){
          C[G[i].at(j).first]=0;
          que.push(G[i].at(j).first);
        }
      }
    }
  }
  for(int i=0;i<N;i++){
    cout<<C[i]<<endl;
  }
  return 0;
}

