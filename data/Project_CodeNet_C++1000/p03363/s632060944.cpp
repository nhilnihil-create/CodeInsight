#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
  cin>>N;
  vector<int64_t>A(N);
  for(int i=0;i<N;i++)
    cin>>A.at(i);
  vector<int64_t>B(N+1);
  B.at(0)=0;
  for(int i=1;i<N+1;i++)
    B.at(i)=B.at(i-1)+A.at(i-1);
  map<int64_t,int64_t>M;
  for(int i=0;i<N+1;i++){
  if(M.count(B.at(i)))
     M.at(B.at(i))++;
     else
     M[B.at(i)]=1;
  
  }int64_t ans=0;
     for(auto p:M){
     auto k=p.first;
       auto v=p.second;
       ans+=(v*(v-1))/2;
     
     }cout<<ans<<endl;
   return 0;
}