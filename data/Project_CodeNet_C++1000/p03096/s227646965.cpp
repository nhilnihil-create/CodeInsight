#include<bits/stdc++.h>
using namespace std;
static const int mod=1000000007;
int main(){
int N;
  cin>>N;
  vector<int>C(N);
  for(int i=0;i<N;i++)
    cin>>C.at(i);
  vector<int64_t>Count(N);
  Count.at(N-1)=1;
  map<int,int>M; M[C.at(N-1)]=N-1;
  for(int i=N-2;0<=i;i--){
  if(!M.count(C.at(i))){
  M[C.at(i)]=i; Count.at(i)=Count.at(i+1);
  }else{
  int j=M.at(C.at(i)); M.at(C.at(i))=i;
    if(j==i+1)
      Count.at(i)=Count.at(j);
    else
      Count.at(i)=(Count.at(i+1)+Count.at(j))%mod;
  }
  }cout<<Count.at(0)<<endl;
    return 0;
}