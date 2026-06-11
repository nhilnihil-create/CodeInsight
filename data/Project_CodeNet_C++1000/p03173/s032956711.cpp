#include <bits/stdc++.h>
using namespace std;
const int MAXN = 405;
int64_t dp[MAXN][MAXN]; // iからjまで合体させるための最小コスト
int64_t S[MAXN];
vector<int64_t> A(MAXN);

int64_t cost(int l, int r)
{
  if (dp[l][r] > 0)
    return dp[l][r];
  if (l == r)
    return dp[l][r] = 0;
  int64_t ret = (1LL << 62);
  for (int i = l; i < r; i++)
  {
    ret = min(ret, (cost(l, i) + (S[i + 1] - S[l]) + cost(i + 1, r) + (S[r + 1] - S[i + 1])));
  }
  return dp[l][r] = ret;
}

int main()
{
  int N;
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++)
  {
    S[i + 1] += S[i] + A[i];
  }
  cout << cost(0, N - 1) << endl;
}
