#include <bits/stdc++.h>
using namespace std;
const int64_t INF = (1LL << 62);

int main()
{
  int N, t = 0;
  double v;
  cin >> N;
  vector<double> T(N), maxv(40010, INF);
  maxv[0] = 0;
  for (int i = 0; i < N; i++)
    cin >> T.at(i);
  for (int i = 0; i < N; i++)
  {
    cin >> v;
    for (int j = 0; j <= T.at(i) * 2; j++)
    {
      maxv.at(t + j) = min(v, maxv.at(t + j));
    }
    t += T.at(i) * 2;
  }
  maxv[t] = 0;
  for (int i = 1; i <= t; i++)
    maxv[i] = min(maxv[i], maxv[i - 1] + 0.5);
  for (int i = t - 1; i >= 0; i--)
    maxv[i] = min(maxv[i], maxv[i + 1] + 0.5);
  double ans = 0;
  for (int i = 1; i <= t; i++)
    ans += ((maxv[i - 1] + maxv[i]) * 0.5) / 2.0;
  cout << fixed << setprecision(15) << ans << endl;
}
