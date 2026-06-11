/* In the name of Allah */

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define pb push_back
#define LL_INF 1LL << 62
#define INF 1 << 30
#define SetBit(x, k) (x |= (1LL << k))
#define ClearBit(x, k) (x &= ~(1LL << k))
#define CheckBit(x, k) (x & (1LL << k))
#define mod 1000000007

int n;
ll x[100005][3];
ll dp[100005][3];

ll solve(int pos, int prev){
  if(pos >= n) return 0;

  if(prev != -1 && dp[pos][prev] != -1) return dp[pos][prev];

  ll res = 0;
  for(int i = 0; i < 3; i++){
    if(i == prev) continue;
    res = max(res, x[pos][i]+solve(pos+1, i));
  }
  
  return dp[pos][prev] = res;
}

int main()
{
  memset(dp, -1, sizeof dp);
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> x[i][0] >> x[i][1] >> x[i][2];

  cout << solve(0, -1) << "\n";

  return 0;
}