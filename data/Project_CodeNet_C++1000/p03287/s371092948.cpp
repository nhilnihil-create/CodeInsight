#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
  ll n,m;
  cin>>n>>m;
  vector<ll> a(n+1);
  vector<ll> b(n+1);

  rep(i,n)cin>>a[i];
  b[0]=0;
  map<ll,ll> mp;

  rep(i,n){
    b[i+1]=(b[i]+a[i])%m;
    mp[b[i+1]]++;
  }
  ll cnt=0;
  for( auto i = mp.begin(); i != mp.end() ; ++i ) {
      ll m1=i->first;
      ll m2=i->second;
      if (m1==0)cnt+=m2;
      cnt+=(m2*(m2-1))/2;
   }
   cout<<cnt;

}
