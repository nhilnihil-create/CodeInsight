#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, x, y, h, ch;
  cin >> N;
  vector<tuple<int64_t, int64_t, int64_t>> vt;
  for (int i = 0; i < N; i++)
  {
    cin >> x >> y >> h;
    vt.push_back({h, x, y});
  }
  sort(vt.begin(), vt.end());
  reverse(vt.begin(), vt.end());
  for (int cx = 0; cx <= 100; cx++)
  {
    for (int cy = 0; cy <= 100; cy++)
    {
      int64_t fx, fy, fh, H, xi, yi, hi;
      tie(fh, fx, fy) = vt.at(0);
      H = fh + abs(fx - cx) + abs(fy - cy);
      bool ok = true;
      for (int i = 0; i < N; i++)
      {
        tie(hi, xi, yi) = vt.at(i);
        if (hi != max(H - abs(xi - cx) - abs(yi - cy), (int64_t)0))
          ok = false;
      }
      if (ok)
      {
        cout << cx << ' ' << cy << ' ' << H << endl;
        return 0;
      }
    }
  }
}