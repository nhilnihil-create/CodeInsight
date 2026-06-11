#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int>>;
int main(){
int N,M;
  cin>>N>>M;
  Graph G(N);
  for(int i=0;i<M;i++){
  int x,y,z;
    cin>>x>>y>>z;
    x--; y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }vector<int>color(N+1,0);
  int a=0;
  int ans=0;
  
  for(int i=1 ; ;i++){
  
    for(int j=a;j<=N;j++)
  if(color.at(j)==0){a=j; break;}
    if(a==N)break;
      ans=i;
    queue<int>que; que.push(a);
   color.at(a)=i;
    while(!que.empty()){
    int v=que.front();
      que.pop();
      for(auto u:G[v]){
      if(color.at(u)!=0)
        continue;
        else{
          color.at(u)=i;
          que.push(u);
        }
      }
    
    } 
    
  }cout<<ans<<endl;
  
   return 0;
}