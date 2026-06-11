#include<bits/stdc++.h>
using namespace std;

using ll = int64_t;

signed main(){

  ll n;
  cin>>n;

  for(ll a=1;a<=3500;++a)for(ll b=1;b<=3500;++b){
    if(4*a*b-n*a-n*b==0)continue;
    ll c = n*a*b/(4*a*b-n*a-n*b);
    if(c<0)continue;
    if(4*a*b*c==n*(a*b+a*c+b*c)){
      cout<<a<<" "<<b<<" "<<c<<endl;
      return 0;
    }
  }

}