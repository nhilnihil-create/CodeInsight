#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int main(){
  LL N,P;
  cin>>N>>P;
  for(LL i=pow(P,1.0/N)+1;i>=1;i--){
    if(P%LL(pow(i,N))==0){
      cout<<i<<endl;
      return 0;
    }
  }
  cout<<1<<endl;
}