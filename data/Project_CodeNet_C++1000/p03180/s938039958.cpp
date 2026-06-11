
#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const int INF=1001001001;

// auto mod int
// https://youtu.be/L8grWxBlIZ4?t=9858
// https://youtu.be/ERZuLAxZffQ?t=4807 : optimize
// https://youtu.be/8uowVvQ_-Mo?t=1329 : division
const int mod = 1000000007;

int main(){
  ll n;
  cin>>n;
  vector<vector<ll>> a(n, vector<ll>(n,0));
  rep(i,n)rep(j,n)cin>>a[i][j];
  vector<ll> dp((1<<n),0);

  for(ll s=0;s<(1<<n);s++){
//    cout<<s<<"s"<<endl;
    ll now=0;
    rep(i,n)for (ll j=i+1;j<n;j++){
      if (((s>>i)&1) && ((s>>j)&1)){
        now+=a[i][j];
    //  cout<<"i"<<i<<"j"<<j<<endl;
    //  cout<<a[i][j]<<endl;
    }
    }
    dp[s]=now;


    for(ll t=(s-1)&s;t>0;t=(t-1)&s){
      dp[s]=max(dp[s],dp[t]+dp[s^t]);
      //cout<<"dp"<<dp[s]<<"s"<<s<<"t"<<t<<endl;
    }
//cout<<dp[s]<<"s"<<s<<endl;
  }

  cout<<dp[(1<<n)-1];
}
