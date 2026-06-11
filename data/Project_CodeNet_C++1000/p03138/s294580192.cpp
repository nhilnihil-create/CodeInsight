#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=a;i<b;i++)
#define rrep(i,b,a) for(ll i=b;i>=a;i--)
#define ll long long
using namespace std;
void optimizeIO(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
void  solve(){
  ll n,k;
  cin>>n>>k;
  ll a[n];
  rep(i,0,n) cin>>a[i];
  vector<ll> dp(60,0);

  rep(i,0,n){
    ll t=a[i];
    for(int j=0;j<50;j++){
         dp[j]+=t%2;
         t/=2;
    }
  }

  ll num=0LL,ans=0LL;
  rrep(j,59,0){
    ll c=dp[j];
    if(c<n-c){
      ll temp=num+(1LL<<j);
      if( temp<=k){
        num= temp;
        ans+=((n-c)*(1LL<<j));
      }
      else ans+= (c*(1LL<<j));
    }
    else ans+= (c*(1LL<<j));
  }

  cout<<ans;
}
int main(){
    optimizeIO();
    solve();
}
