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

int n, k;
ll x[100005];
ll dp[100005];

ll solve(int pos){
  if(pos>=n-1) return 0;
  if(dp[pos]!=-1) return dp[pos];

  ll res = LL_INF;
  for(int i = 1; i <= k; i++)
    if(pos+i<n)
      res = min(res, abs(x[pos+i]-x[pos])+solve(pos+i));
  
  return dp[pos] = res;
}

int main()
{
  memset(dp, -1, sizeof dp);
  cin >> n >> k;
  for(int i = 0; i < n; i++)
    cin >> x[i];

  cout << solve(0) << "\n";

  return 0;
}