#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
  ll n,ans=0;
  cin>>n;
  for(ll i=1;i*i<=n;i++){
    if((n-i)%i!=0){
      continue;
    }
    ll x=(n-i)/i;
    if(x==0){
      continue;
    }
    if(n/x==n%x){
      ans+=x;
    }
  }
  cout<<ans<<endl;
}