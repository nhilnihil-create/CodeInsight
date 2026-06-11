#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

const ll MAXN = 505;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);cout.tie(0);

  ll n, m, q;
  cin >> n >> m >> q;
  vector < vector < ll > > dp(MAXN, vector < ll > (MAXN, 0));
  for(int i = 0; i < m; i++){
    ll l, r;
    cin >> l >> r;
    dp[l][r]++;
  }
  
  for(int i = MAXN - 1; i >= 0; i--){
    for(int j = i + 1; j < MAXN; j++){
      dp[i][j] += dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
    }
  }

  while(q--){
    ll l, r;
    cin >> l >> r;
    cout << dp[l][r] << '\n';
  }
}
