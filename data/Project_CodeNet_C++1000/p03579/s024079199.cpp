#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<ll>A;
using Graph=vector<vector<ll>>;
ll N,M;
int main(){
  cin>>N>>M;
  Graph G(N);
  A.resize(N,-1);
  for(ll i=0;i<M;i++){
  ll u,v;cin>>u>>v;u--;v--;
    G[u].push_back(v);
    G[v].push_back(u);
  }bool judge=true;
  queue<ll>que;que.push(0);
  A[0]=0;
  while(!que.empty()){
  ll v=que.front();que.pop();
    for(auto u:G[v]){
    if(A[u]==A[v]){judge=false;break;}
      if(A[u]!=-1)
               continue;
               A[u]=1-A[v];
               que.push(u);
    }
  if(!judge)break;
  
  }
  if(!judge)
               cout<<((N*(N-1))/2)-M<<endl;
               else{
               ll sum=0;
                 for(ll i=0;i<N;i++)
                   if(A[i]==0)
                     sum+=1;
                 cout<<(sum*(N-sum))-M<<endl;
                }
  return 0;
}
