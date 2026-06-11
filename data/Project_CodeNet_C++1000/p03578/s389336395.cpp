#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  map<int64_t,int>D;
  for(int i=0;i<N;i++){
  int64_t d;
    cin>>d;
    if(D.count(d))
      D.at(d)++;
    else
      D[d]=1;
  
  }int M;
  cin>>M;
  map<int64_t,int>T;
  for(int i=0;i<M;i++){
  int64_t t;
    cin>>t;
    if(T.count(t))
      T.at(t)++;
    else
      T[t]=1;
  }string ans="YES";
  for(auto p:T){
  auto k=p.first;
    auto v=p.second;
    if(!D.count(k) || D.at(k)<T.at(k)){
    ans="NO"; break;
    }
  
  }cout<<ans<<endl;

   return 0;
}