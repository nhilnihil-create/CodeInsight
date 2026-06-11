#include<bits/stdc++.h>
using namespace std;
int main(){
int N,K;
  cin>>N>>K;
  map<int,int>M;
  for(int i=0;i<N;i++){
  int a;
    cin>>a;
    if(M.count(a))
      M.at(a)++;
    else
      M[a]=1;
  
  }vector<int>A={0};
  for(auto p:M){
  auto k=p.first;
    auto v=p.second;
    A.push_back(v);
  
  }sort(A.begin(),A.end());
  int m=A.size();
  if(m-1<=K)
    cout<<0<<endl;
  else{
   int ans=0;
    for(int i=1;i<=m-K-1;i++)
      ans+=A.at(i);
    cout<<ans<<endl;
  }
  
   return 0;
}