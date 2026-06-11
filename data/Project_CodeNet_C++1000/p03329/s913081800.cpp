#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  
  vector<int> dp(100010,0);
  dp[0] = 0;
  for (int n = 1; n <= 100000; n++) {
    dp[n] = 1000000;
    int p = 1;
    while (p <= n){
      dp[n] = min(dp[n], dp[n-p] + 1);
      p *= 6;
    }
    p = 1;
    while (p <= n){
      dp[n] = min(dp[n], dp[n-p] + 1);
      p *= 9;
    }
  }

  cout << dp[n] << endl;

}