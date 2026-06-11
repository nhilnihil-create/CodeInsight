#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
int s(ll n){
  int ans=0;
  while(n)
    ans+=n%10,n/=10;
  return ans;
}
ll f(ll n){
  ll ans=n,d=1,v; ld mn=(ld)n/s(n),sum;
  while(d<n){
    d*=10,v=n/d*d+d-1,sum=(ld)v/s(v);
    if (sum<mn)
      mn=sum,ans=v;
  }
  return ans;
}
int main(){
  int k; cin>>k;
  for (ll n=1; k--; n=f(n+1))
    printf("%lld\n",n);
  return 0;
}