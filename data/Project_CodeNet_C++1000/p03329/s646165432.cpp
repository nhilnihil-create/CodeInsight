#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (ll i = (a); i < (b); i++)
#define repe(i, a, b) for (ll i = (a); i <= (b); i++)

template<class T> inline bool chmax(T& a, T b){
  if (a < b) { a = b; return true; } return false;
}
ll INF = 1LL<<60;

int dp[100010] = {0};

int
main(void)
{
  int n; cin >> n;
  repe(i, 0, n) dp[i] = i;

  for(int i = 0; i <= n; i++){
    for(int k = 1; i + pow(6, k) <= n; k++){
      int index = pow(6, k);
      dp[i + index] = min(dp[i + index], 1 + dp[i]);
    }
  }

  for(int i = 0; i <= n; i++){
    for(int k = 1; i + pow(9, k) <= n; k++){
      int index = pow(9, k);
      dp[i + index] = min(dp[i + index], 1 + dp[i]);
    }
  }


  cout << dp[n] << endl;

  return 0;
}