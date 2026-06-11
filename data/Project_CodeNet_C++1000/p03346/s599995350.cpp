#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int>P(N);
  for(int i=0;i<N;i++)
    cin>>P.at(i);
  map<int,int>M;
  for(int i=0;i<N;i++){
  if(!M.count(P.at(i)-1))
    M[P.at(i)]=1;
    else
      M[P.at(i)]=M.at(P.at(i)-1)+1;
  }int Max=0;
  for(auto p:M){
  auto k=p.first;
    auto v=p.second;
    if(Max<v)
      Max=v;
}int ans=N-Max;
  cout<<ans<<endl;
  
   return 0;
}