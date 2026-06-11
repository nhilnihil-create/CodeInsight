#include<bits/stdc++.h>
#define F first
#define S second
#define REP(i, a, b, c) for(int i = a; i <= b; i+=c)
#define pb push_back
#define int unsigned long long int
#define MAX 1e18
#define MOD 1000000007
using namespace std;

int dp[405][405];

int csum(int a[], int s, int e)
{
  int ans = 0;
  for (int i = s; i <= e; i++)
    ans = (ans + a[i]);
  return ans;
}

int solve(int a[], int i, int j) {
  if (i >= j)
    return  0;
  if (dp[i][j] != -1)
    return dp[i][j];
  dp[i][j] = MAX;
  for (int k = i; k < j; k++)
  {
    dp[i][j] = min(dp[i][j], solve(a, i, k) + solve(a, k + 1, j) + csum(a, i, k) + csum(a, k + 1, j));
  }
  return dp[i][j];
}

int32_t main()
{
  ios :: sync_with_stdio(false); cin.tie(0);
  int t = 1;
  //cin >> t;
  for (int i9 = 1; i9 <= t; i9++)
  {
    int n;
    cin >> n;
    int a[n];
    REP(i, 0, n - 1, 1) {
      cin >> a[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << solve(a, 0, n - 1);
  }

}