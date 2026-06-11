#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, M, ans = 1;
  cin >> N >> M;
  for (int64_t n = 1; n <= sqrt(M); n++)
  {
    if (M % n != 0)
      continue;
    int64_t m = M / n;
    if (m >= N)
      ans = max(ans, n);
    if (n >= N)
      ans = max(ans, m);
  }
  cout << ans << endl;
}