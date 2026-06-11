#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
int64_t dp[MAXN]; // 最大の高さがiの時の最大値

int main()
{
  int N;
  cin >> N;
  int base = 1;
  while (base <= N)
  {
    base *= 2;
  }
  vector<int64_t> Tree(2 * base);

  vector<int64_t> H(N), A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> H[i];
  }
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++)
  {
    int x = H[i] + base;
    int64_t best = 0;
    while (x > 1)
    {
      if (x % 2 == 1)
      {
        best = max(best, Tree[x - 1]);
      }
      x /= 2;
    }
    dp[H[i]] = best + A.at(i);
    for (int j = base + H[i]; j >= 1; j /= 2)
    {
      Tree[j] = max(Tree[j], dp[H[i]]);
    }
  }
  int64_t ans = 0;
  for (int i = 0; i <= N; i++)
  {
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}
