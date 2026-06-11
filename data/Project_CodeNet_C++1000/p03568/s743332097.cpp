#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

int main(){ 
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  vector<int> dp(2,0);
  dp[1] = 1;
  //dp[0] = 1;
  for (int i = 0; i < n; i++) {
    vector<int> next(2, 0);
    for (int d = 0; d <= 101; d++) {
      if (abs(a[i] - d) > 1) continue;
      if (d & 1) {
        next[0] += dp[0];
        next[1] += dp[1];
      } else {
        next[0] += dp[0] + dp[1];
      }
    }
    dp = next;
  }
  cout << dp[0] << endl;
  return 0;
} 