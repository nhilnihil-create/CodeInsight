#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<tuple<int64_t, int, int>> vt(n);
  for (int i = 0; i < n; i++)
  {
    int64_t x, y, h;
    cin >> x >> y >> h;
    vt[i] = make_tuple(h, x, y);
  }
  sort(vt.begin(), vt.end());
  reverse(vt.begin(), vt.end());
  for (int i = 0; i <= 100; i++)
  {
    for (int j = 0; j <= 100; j++)
    {
      int64_t h0, x0, y0;
      tie(h0, x0, y0) = vt[0];
      int64_t H = h0 + abs(x0 - i) + abs(y0 - j);
      if (H <= 0)
      {
        continue;
      }
      bool ok = true;
      for (int k = 0; k < n; k++)
      {
        int64_t hk, xk, yk;
        tie(hk, xk, yk) = vt[k];
        int64_t h = max(H - abs(i - xk) - abs(j - yk), (int64_t)0);
        if (h != hk)
        {
          ok = false;
          break;
        }
      }
      if (ok)
      {
        cout << i << ' ' << j << ' ' << H << endl;
        return 0;
      }
    }
  }
}