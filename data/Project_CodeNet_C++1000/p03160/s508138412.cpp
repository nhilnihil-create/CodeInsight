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
ll x[100005];
ll dp[100005];

ll solve(int pos){
  if(pos>=n-1) return 0;
  if(dp[pos]!=-1) return dp[pos];

  ll res = LL_INF;
  if(pos+1<n) res = min(res, abs(x[pos+1]-x[pos])+solve(pos+1));
  if(pos+2<n) res = min(res, abs(x[pos+2]-x[pos])+solve(pos+2));

  return dp[pos] = res;
}

int main()
{
  memset(dp, -1, sizeof dp);
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> x[i];

  cout << solve(0) << "\n";

  return 0;
}