#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
const int mod = 1000000007;

ll dp[55][2];
int main(){
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) {
    cin >> a[i];
  }
  vector<ll> cnt(50);

  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < 50; ++j) {
      cnt[j] += (a[i]>>j)&1;
    }
  }
  rep(i, 55) {
    rep(j, 2) dp[i][j] = -1;
  }
  dp[50][0] = 0;
  
  for (int i = 49; i >= 0; --i) {
    ll t = 1LL << i;

    ll score0 = cnt[i] * t;
    ll score1 = (n - cnt[i]) * t;

    if(dp[i + 1][1] != -1) {
      dp[i][1] = max(dp[i][1], dp[i + 1][1] + max(score0, score1));
    }
    if(dp[i + 1][0] != -1) {
      if(k & t) {
        dp[i][1] = max(dp[i][1], dp[i + 1][0] + score0);
        dp[i][0] = max(dp[i][0], dp[i + 1][0] + score1);
      } else {
        dp[i][0] = max(dp[i][0], dp[i + 1][0] + score0);
      }
    }
  }
  cout << max(dp[0][0], dp[0][1]) << endl;
  
}