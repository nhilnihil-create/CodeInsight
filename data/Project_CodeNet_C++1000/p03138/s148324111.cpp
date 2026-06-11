#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (ll i = 0; i < (n); i++)
typedef pair<ll,ll> P;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main(){

  ll n,k;
  cin >> n >> k;

  vector<ll> cnt(50,0);
  vector<ll> two(50,1);
  rep(i,49){
    two[i+1] = two[i]*2;
  }
  rep(i,n){
    ll a;
    cin >> a;
    rep(j,50){
      if(a>>j&1){
        cnt[j]++;
      }
    }
  }

  vector<vector<ll>> dp(51, vector<ll>(2));
  for(ll i = 49; i >= 0 ;i--){
    ll d = two[i];

    if(k>>i&1){
      dp[i][1] = dp[i+1][1] + (n-cnt[i])*two[i];
    }else{
      dp[i][1] = dp[i+1][1] + cnt[i]*two[i];
    }

    if(dp[i+1][0]>0){
      dp[i][0] = dp[i+1][0] + max(cnt[i], n-cnt[i])*two[i];
    }
    if(k>>i&1){
      dp[i][0] = max(dp[i][0], dp[i+1][1]+cnt[i]*two[i]);
    }
  }

  cout << max(dp[0][0], dp[0][1]) << endl;

  return 0;
} 