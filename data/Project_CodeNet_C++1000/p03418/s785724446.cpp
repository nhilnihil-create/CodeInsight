#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K, r, p, ans = 0, zero = 0, one = 1;
  cin >> N >> K;
  for (int b = 1; b <= N; b++)
  {
    ans += max(b - K, zero) * (N / b);
    ans += max((N % b) - max(one, K) + 1, zero);
  }
  cout << ans << endl;
}