#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


int main()
{
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n)
    cin >> a[i];
  ll c = 1, d = 1;
  while (d<<1 <= 1e12)
  {
    d <<= 1;
    c++;
  }
  vector<int> count(c, 0);
  rep(i, n)
    rep(j, c)
    {
      if (a[i] & 1)
        count[j]++;
      a[i] >>= 1;
    }
  vector<vector<ll>> dp(c + 1, vector<ll>(2));
  for (int i=c-1; i>=0; i--)
  {
    if (k & d)
      dp[i][1] = dp[i+1][1] + (n - count[i]) * d;
    else
      dp[i][1] = dp[i+1][1] + count[i] * d;
    if (dp[i+1][0] > 0)
      dp[i][0] = dp[i+1][0] + max(count[i], n - count[i]) * d;
    if (k & d)
      dp[i][0] = max(dp[i][0], dp[i+1][1] + count[i] * d);
    d >>= 1;
  }
  cout << max(dp[0][0], dp[0][1]) << endl;
  return 0;
}