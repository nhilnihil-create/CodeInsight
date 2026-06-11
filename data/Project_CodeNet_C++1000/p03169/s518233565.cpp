#include <bits/stdc++.h>
using namespace std;
double dp[310][310][310];
int N, c[4];

double solve(int i, int j, int k)
{
  if (i == 0 && j == 0 && k == 0)
    return 0.0;
  if (dp[i][j][k] > 0)
    return dp[i][j][k];
  double p = N;
  if (i > 0)
    p += solve(i - 1, j, k) * i;
  if (j > 0)
    p += solve(i + 1, j - 1, k) * j;
  if (k > 0)
    p += solve(i, j + 1, k - 1) * k;
  p /= (i + j + k);
  return dp[i][j][k] = p;
}

int main()
{
  int a;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> a;
    c[a]++;
  }
  cout << fixed << setprecision(10) << solve(c[1], c[2], c[3]) << endl;
}
