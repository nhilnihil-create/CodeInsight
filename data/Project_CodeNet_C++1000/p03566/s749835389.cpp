#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;

using namespace std;

int main()
{
  double maxv[40001] = {};
  int t[100] = {};
  // 何秒から始まるか(長さはt[i]を見るとわかる)
  pair<int, double> v[100] = {};
  int n;
  int T = 0;
  cin >> n;
  REP(i, n)
  {
    cin >> t[i];
  }
  REP(i, n)
  {
    double vi;
    cin >> vi;
    v[i] = make_pair(T, vi);
    T += t[i];
  }

  REP(i, 2 * T + 1)
  {
    maxv[i] = 50000;
  }

  // maxv[i]を決める
  // t = i/2
  REP(i, 2 * T + 1)
  {
    maxv[i] = min(maxv[i], (double)i / 2);
    maxv[i] = min(maxv[i], (double)T - (double)i / 2);
    REP(j, n)
    {
      if ((double)i / 2 < v[j].first)
      {
        maxv[i] = min(maxv[i], v[j].second + ((double)(2 * v[j].first - i) / 2));
      }
      else if ((double)i / 2 > v[j].first + t[j])
      {
        maxv[i] = min(maxv[i], v[j].second + ((double)(i - 2 * (v[j].first + t[j])) / 2));
      }
      else
      {
        maxv[i] = min(maxv[i], v[j].second);
      }
    }
  }

  double ans = 0;
  FOR(i, 1, 2 * T + 1)
  {
    ans += 0.25 * (maxv[i - 1] + maxv[i]);
  }

  cout << fixed << setprecision(6) << ans << endl;
}
