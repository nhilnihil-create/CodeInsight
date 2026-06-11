#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
int main(){
int N,M;
  cin>>N>>M;
  vector<pair<int,int>>A(M);
  for(int i=0;i<M;i++){
  int a,b;
    cin>>a>>b;
    pair<int,int>p(a,b);
    A.at(i)=p;
  }int ans=0;
  for(int i=0;i<M;i++){
  Graph G(N);
    for(int j=0;j<M;j++){
    if(j!=i){
      int a=A.at(j).first-1;
      int b=A.at(j).second-1;
      G[a].push_back(b);
      G[b].push_back(a);
    }
    }
    queue<int>que;
    que.push(0);
    vector<bool>J(N,false);
    J.at(0)=true;
    while(!que.empty()){
      int u=que.front();
      que.pop();
      for(auto v:G[u]){
      if(J[v])
        continue;
        else{
        J.at(v)=true;
          que.push(v);
        }
      
      }
    
    } bool x=true;
    for(int i=0;i<N;i++)
      if(!J.at(i)){x=false; break;}
    
    if(!x)
      ans++;
  }cout<<ans<<endl;
   return 0;
}