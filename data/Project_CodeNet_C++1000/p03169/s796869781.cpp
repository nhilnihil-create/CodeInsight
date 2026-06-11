#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int n;
vector<vector<vector<double>>> dp;

double rec(int i, int j, int k)
{
  if (dp[i][j][k] != -1)
    return dp[i][j][k];
  double d = i + j + k;
  dp[i][j][k] = (n - d) / d;
  if (i > 0)
    dp[i][j][k] += (rec(i - 1, j, k) + 1) * i / d;
  if (j > 0)
    dp[i][j][k] += (rec(i + 1, j - 1, k) + 1) * j / d;
  if (k > 0)
    dp[i][j][k] += (rec(i, j + 1, k - 1) + 1) * k / d;
  return dp[i][j][k];
}

int main()
{
  cin >> n;
  map<int, int> m;
  rep(i, n)
  {
    int a;
    cin >> a;
    m[a]++;
  }
  dp.resize(n + 1);
  rep(i, n + 1)
  {
    dp[i].resize(n + 1);
    rep(j, n + 1)
    {
      dp[i][j].resize(n + 1);
      fill(dp[i][j].begin(), dp[i][j].end(), -1);
    }
  }
  dp[0][0][0] = 0;
  printf("%.10lf\n", rec(m[1], m[2], m[3]));
  return 0;
}