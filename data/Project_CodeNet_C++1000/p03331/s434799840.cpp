#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, a = 0, ans = 0;
  cin >> N;
  while (N > 0)
  {
    ans += (N % 10);
    a += (N % 10);
    N /= 10;
  }
  if (a == 1)
    ans *= 10;
  cout << ans << endl;
}