#include<bits/stdc++.h>
using namespace std;

int main(){

  long long N,i,Sum=0;
  cin>>N;
  map<long long, long long> A;
  
  for(i=0;i<N;i++){
    long long a;
    cin>>a;
    A[a]++;
  }
  
  for(auto p:A){
    
    if(p.first>p.second)Sum+=p.second;
    if(p.first<p.second)Sum+=p.second-p.first;
  }
  cout<<Sum<<endl;
  return 0;
}