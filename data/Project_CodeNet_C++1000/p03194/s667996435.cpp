#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n,p;
  cin>>n>>p;
  ll ans=1;
  for(ll i=2;i*i<=p;i++){
    if(p%i==0){
      int x=0;
      while(p%i==0){
        p/=i;
        x++;
      }
      if(x>=n){
        ans*=pow(i,x/n);
      }
    }
  }
  if(p>1){
    if(n==1){
      ans*=p;
    }
  }
  cout<<ans<<endl;
}