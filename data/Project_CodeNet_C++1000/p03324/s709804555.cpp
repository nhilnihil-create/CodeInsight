#include<bits/stdc++.h>
using namespace std;

int main(){
  int D,N;cin>>D>>N;
  int ans;
  if(D==0) ans=1;
  if(D==1) ans=100;
  if(D==2) ans=10000;
  if(N!=100)cout<<ans*N<<endl;
  else cout<<ans*(N+1)<<endl;
}

