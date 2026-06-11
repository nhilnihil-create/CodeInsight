#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define printVector(v) rep(i, v.size()) cout << v[i] << endl;

int main()
{
  int N, C;
  cin >> N >> C;
  vector<pair<pair<int, int>, int>> programs(N);
  vector<vector<int>> time(C, vector<int>(2 * pow(10, 5) + 10, 0));

  rep(i, N)
  {
    int s, e, c;
    cin >> s >> e >> c;
    time[c - 1][2 * s]++;
    time[c - 1][2 * e]--;
  }
  rep(c, C) rep(t, time[0].size())
  {
    if (time[c][t] == -1)
    {
      time[c][t] = 0;
      time[c][t + 1]--;
      t++;
    }
  }

  rep(c, C) rep(t, time[0].size() - 1)
  {
    time[c][t + 1] += time[c][t];
  }

  int ans = 0;
  rep(t, time[0].size())
  {
    int count = 0;
    rep(c, C)
    {
      count += time[c][t];
    }
    ans = max(ans, count);
  }
  cout << ans << endl;
  return 0;
}