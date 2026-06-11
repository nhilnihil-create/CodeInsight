#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, K, x, y, ans = (1LL << 62);
  cin >> N >> K;
  vector<pair<int64_t, int64_t>> xy(N);
  for (int i = 0; i < N; i++)
  {
    cin >> x >> y;
    xy.at(i) = make_pair(x, y);
  }
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      int64_t xmin = xy[i].first, xmax = xy[j].first;
      if (xmin >= xmax)
        continue;
      for (int k = 0; k < N; k++)
      {
        for (int l = 0; l < N; l++)
        {
          int64_t ymin = xy[k].second, ymax = xy[l].second;
          if (ymin >= ymax)
            continue;
          int64_t cnt = 0;
          for (auto p : xy)
          {
            tie(x, y) = p;
            if (x >= xmin && x <= xmax && y >= ymin && y <= ymax)
              cnt++;
            if (cnt >= K)
              ans = min(ans, (xmax - xmin) * (ymax - ymin));
          }
        }
      }
    }
  }
  cout << ans << endl;
}
