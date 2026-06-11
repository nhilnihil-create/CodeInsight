#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N, total = 0;
  cin >> N;
  vector<double> T(N), V(N);
  for (int i = 0; i < N; i++)
  {
    cin >> T.at(i);
    total += T.at(i);
  }
  for (int i = 0; i < N; i++)
  {
    cin >> V.at(i);
  }
  vector<double> maxV(total * 2 + 1, 10000);
  maxV[0] = 0, maxV[total * 2] = 0;
  int l = 0;
  for (int i = 0; i < N; i++)
  {
    for (int t = l; t <= l + T.at(i) * 2; t++)
    {
      maxV[t] = min(maxV[t], V.at(i));
    }
    l += T.at(i) * 2;
  }
  for (int t = 1; t <= total * 2; t++)
  {
    maxV[t] = min(maxV[t], maxV[t - 1] + 0.5);
  }
  for (int t = total * 2 - 1; t >= 0; t--)
  {
    maxV[t] = min(maxV[t], maxV[t + 1] + 0.5);
  }
  double ans = 0.0;
  for (int t = 0; t <= total * 2; t++)
  {
    ans += maxV[t] * 0.5;
  }
  cout << fixed << setprecision(10) << ans << endl;
}