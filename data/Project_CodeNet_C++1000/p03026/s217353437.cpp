#include<bits/stdc++.h>
using namespace std;
using Graph=vector<vector<int64_t>>;
int main(){
  int N;cin>>N;
  Graph G(N);
  for(int i=0;i<N-1;i++){
  int64_t a,b;cin>>a>>b;a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }vector<int64_t>c(N);
  for(int i=0;i<N;i++)
    cin>>c.at(i);
  sort(c.begin(),c.end());
  reverse(c.begin(),c.end());
  int64_t M=0;
  for(int i=1;i<N;i++)
    M+=c.at(i);
  vector<int64_t>d(N,-1);d[0]=c.at(0);
  queue<int64_t>que;
  for(int i=1;i<N;i++)
    que.push(c.at(i));
  queue<int64_t>que1;que1.push(0);
  while(!que1.empty()){
  int64_t u=que1.front();
    que1.pop();
    for(auto v:G[u]){
    if(d[v]!=-1)
      continue;
      else{
      int64_t a=que.front();
        que.pop();
        d[v]=a;
        que1.push(v);
      }
    }
  }cout<<M<<endl;
  for(int i=0;i<N-1;i++)
    cout<<d[i]<<" ";
  cout<<d[N-1]<<endl;
  
  return 0;
}