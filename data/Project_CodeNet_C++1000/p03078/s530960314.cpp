#include<bits/stdc++.h>
using namespace std;

int main(){
  long long x,y,z,k,e;
  vector<long long>v1,v2,nv1,nv2;
  priority_queue<long long>pq1,pq2;
  cin>>x>>y>>z>>k;
  for(long long i=0;i<x;i++){
    cin>>e;v1.push_back(e);
  }
  for(long long i=0;i<y;i++){
    cin>>e;v2.push_back(e);
  }
  for(auto i:v1){
    for(auto j:v2){
      pq1.push(i+j);
    }
  }
  for(long long i=0;!pq1.empty()&&i<3000;i++){
    nv1.push_back(pq1.top());
    pq1.pop();
  }
  for(long long i=0;i<z;i++){
    cin>>e,nv2.push_back(e);
  }
  sort(nv2.begin(),nv2.end());
  for(auto i:nv1){
    for(auto j:nv2){
      pq2.push(i+j);
    }
  }
  for(long long i=0;i<k;i++){
    cout<<pq2.top()<<"\n";
    pq2.pop();
  }
  return 0;
}