#include <bits/stdc++.h>
using namespace std;
#define ffor(n) for(int i = 0; i < n; i++)
#define fffor(n) for(int j = 0; j < n; j++)
int INF = 1e9 + 7;
long long INF2 = 1e16;

long long f(int l, int r, vector <long long>& v, vector <vector <long long>>& dp, vector <vector <long long>>& range_sum) {
  if (dp[l][r] != -1) return dp[l][r];
  if (l == r) {
    range_sum[l][r] = v[l];
    dp[l][r] = 0;
    return dp[l][r];
  }
  if (l + 1 == r) {
    range_sum[l][r] = v[l] + v[r];
    dp[l][r] = range_sum[l][r];
    return dp[l][r];
  }
  if (l > r) {
    return 0;
  }
  long long ans = INF2;
  for(int i = l; i < r; i++) {
    ans = min(ans, 
              f(l, i, v, dp, range_sum) + f(i + 1, r, v, dp, range_sum) + range_sum[l][i] + range_sum[i + 1][r]);
  }
  dp[l][r] = ans;
  range_sum[l][r] = range_sum[l][l + 1] + range_sum[l + 2][r];
  return ans;
}

int main(void) {
  int n;
  cin >> n;
  vector <long long> v(n);
  ffor(n) cin >> v[i];
  
  vector <vector <long long>> dp(n, vector <long long>(n, -1));
  vector <vector <long long>> range_sum(n, vector <long long>(n, -1));
  
  cout << f(0, n - 1, v, dp, range_sum) << '\n';
}