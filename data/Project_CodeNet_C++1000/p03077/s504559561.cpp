#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
  ll n,a,b,c,d,e;
  cin>>n>>a>>b>>c>>d>>e;
  ll n_a=(n-1)/a;
  ll n_b=(n-1)/b;
  ll n_c=(n-1)/c;
  ll n_d=(n-1)/d;
  ll n_e=(n-1)/e;
  ll ans=max(n_a,max(n_b,max(n_c,max(n_d,n_e))))+5;
  cout<<ans<<endl;
  return 0;
}