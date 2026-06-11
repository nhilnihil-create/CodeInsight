#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, ans = 0;
  cin >> N;
  for (int x = 1; x <= sqrt(N); x++)
  {
    if (N % x == 0)
    {
      int64_t a = (N / x) - 1;
      if (a != 0 && N / a == N % a)
        ans += a;
    }
  }
  cout << ans << endl;
}
