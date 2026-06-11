#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lvector vector<ll>
#define P pair<ll,ll> 
#define rep(i,n) for(ll (i)=0; (i)<(n); ++(i))
#define print(a) cout << (a) << endl

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n,a=0,b=0,c=0;cin>>n;
  bool isok=false;
  for(ll i=1;i<=3500;++i) {
    for(ll j=1;j<=3500;++j) {
      ll div=4*i*j-(i+j)*n;
      if(div<=0) continue;
      if((i*j*n)%div!=0) continue;
      ll k=(i*j*n)/div;
      if(4*i*j*k==(i*j+j*k+k*i)*n) {
        a=k,b=i,c=j;
        isok=true;
      }
      if(isok) break;
    }
    if(isok) break;
  }
  printf("%lld %lld %lld\n",a,b,c);
  return 0;
}