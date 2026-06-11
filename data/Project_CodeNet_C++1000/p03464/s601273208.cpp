#include <bits/stdc++.h>
using namespace std;

int main()
{
  int k;
  cin >> k;
  vector<int64_t> as(k);
  for (int i = 0; i < k; i++)
  {
    cin >> as.at(i);
  }
  int64_t a = 2;
  for (int i = k - 1; i >= 0; i--)
  {
    a = ((a + as.at(i) - 1) / as.at(i)) * as.at(i);
  }
  auto ok = [&](int64_t x) {
    for (int i = 0; i < k; i++)
    {
      x = x - (x % as.at(i));
    }
    return x == 2;
  };
  if (!ok(a))
  {
    cout << -1 << endl;
    return 0;
  }
  int64_t l = a, r = 1LL << 62;
  while (r - l > 1)
  {
    int64_t m = (r + l) / 2;
    if (ok(m))
      l = m;
    else
      r = m;
  }
  cout << a << ' ' << l << endl;
}