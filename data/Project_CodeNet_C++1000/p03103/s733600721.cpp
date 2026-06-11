#include <bits/stdc++.h>
using namespace std;

int main(){
  long long N,M;
  cin>>N>>M;
  map<long long,long long> A;
  for(long long i=0;i<N;i++){
    long long a,b;
    cin>>a>>b;
    A[a]+=b;
  }
  long long j=0;
  for(pair<long long,long long> i:A){
    if(i.second>=M){
      cout<<j+M*i.first<<endl;
      return 0;
    }else{
      j+=i.first*i.second;
      M-=i.second;
    }
  }
}