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
  ll n,k,ans=0;cin>>n>>k;
  if(k==0) ans+=n*n;
  else {
    for(ll b=k+1;b<=n;++b) {
      ll rem=n%b,div=(n-rem)/b;
      ans+=(b-k)*div;
      if(rem>=k) ans+=rem-k+1;
    }
  }
  print(ans);
  return 0;
}