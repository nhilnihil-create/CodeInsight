#include <bits/stdc++.h>
using namespace std;
const int INF = (1 << 29);

int main()
{
  int D, G;
  cin >> D >> G;
  vector<int> p(D), c(D);
  for (int i = 0; i < D; i++)
  {
    cin >> p.at(i) >> c.at(i);
  }
  int ans = INF;
  for (int bit = 0; bit < (1 << D); bit++)
  {
    int now = 0, cnt = 0;
    for (int i = 0; i < D; i++)
    {
      if (bit & (1 << i))
      {
        now += (100 * (i + 1) * p.at(i) + c.at(i));
        cnt += p.at(i);
      }
    }
    if (now >= G)
    {
      ans = min(ans, cnt);
    }
    else
    {
      for (int i = D - 1; i >= 0; i--)
      {
        if (!(bit & (1 << i)))
        {
          if ((G - now) < (100 * (i + 1)) * p.at(i))
          {
            cnt += (G - now) / (100 * (i + 1));
            if ((G - now) % (100 * (i + 1)))
            {
              cnt++;
            }
            ans = min(ans, cnt);
          }
          break;
        }
      }
    }
  }
  cout << ans << endl;
}