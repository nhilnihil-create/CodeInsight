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
  ll n,ans=0;cin>>n;
  for(ll i=1;i*i<=n;++i) {
    if((n-i)%i==0&&(n-i)/i>i) ans+=(n-i)/i;
  }
  print(ans);
  return 0;
}
