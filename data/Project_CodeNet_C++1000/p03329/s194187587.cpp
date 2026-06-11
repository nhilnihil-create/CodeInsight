#include <bits/stdc++.h>
using namespace std;
typedef int64_t ll;

int main(){
  int n,v,si,ni;
  cin>>n;
  vector<int> dist(100001,-1);
  queue<int> q;
  dist[0]=0;
  q.push(0);
  while(!q.empty()){
    v=q.front();
    q.pop();
    if(v+1<=100000 && dist[v+1]==-1){
      dist[v+1]=dist[v]+1;
      q.push(v+1);
    }
    si=6;
    while(v+si<=100000){
      if(dist[v+si]==-1){
        dist[v+si]=dist[v]+1;
        q.push(v+si);
      }
      si*=6;
    }
    ni=9;
    while(v+ni<=100000){
      if(dist[v+ni]==-1){
        dist[v+ni]=dist[v]+1;
        q.push(v+ni);
      }
      ni*=9;
    }
  }
  cout<<dist[n]<<endl;
}
