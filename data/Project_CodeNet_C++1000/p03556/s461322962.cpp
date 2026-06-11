#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, ans;
  cin >> N;
  for (int64_t i = 1; i <= 100000; i++)
  {
    int64_t n = i * i;
    if (n > N)
    {
      cout << ans << endl;
      return 0;
    }
    ans = n;
  }
}
