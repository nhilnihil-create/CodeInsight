#include <bits/stdc++.h>
using namespace std;
const int64_t MAXT = 200010;

int main()
{
  int64_t N, C, s, t, c, ans = 0;
  cin >> N >> C;
  vector<vector<int64_t>> T(31, vector<int64_t>(MAXT, 0));
  for (int i = 0; i < N; i++)
  {
    cin >> s >> t >> c;
    T[c][s * 2 - 1]++;
    T[c][t * 2]--;
  }
  for (int i = 1; i <= 30; i++)
  {
    for (int j = 1; j <= MAXT; j++)
    {
      T[i][j] += T[i][j - 1];
    }
  }
  for (int i = 0; i <= MAXT; i++)
  {
    int64_t tmp = 0;
    for (int j = 1; j <= 30; j++)
    {
      if (T[j][i] >= 1)
        tmp++;
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}