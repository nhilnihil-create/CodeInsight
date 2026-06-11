#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll func(ll n){
    ll t=n%4;
    if(t==0) return n;
    if(t==1) return 1;
    if(t==2) return 1^n;
    else return 0;
}

int main(){
  ll a,b;cin>>a>>b;
  ll ans=func(a-1)^func(b);
  
  cout<<ans;
}