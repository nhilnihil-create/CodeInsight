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
  vector<vector<long long>> D(C, vector<long long>(C, 0));
  rep(i, C) rep(j, C)
  {
    cin >> D[i][j];
  }
  vector<vector<int>> Color(3), c(N, vector<int>(N, 0)), ColorCount(3, vector<int>(C, 0));
  rep(i, N) rep(j, N)
  {
    cin >> c[i][j];
    c[i][j]--;
    ColorCount[(i + j) % 3][c[i][j]]++;
  }
  rep(i, C)
  {
    Color[i % 3].push_back(i);
  }
  long long ans = INT64_MAX;
  rep(i0, C) rep(i1, C) rep(i2, C)
  {
    int C0 = i0;
    int C1 = i1;
    int C2 = i2;
    if (C0 == C1 || C1 == C2 || C2 == C0)
      continue;
    long long cost = 0;
    rep(iC, C)
    {
      long long iCcount0 = ColorCount[0][iC];
      long long iCcount1 = ColorCount[1][iC];
      long long iCcount2 = ColorCount[2][iC];
      cost += D[iC][C0] * iCcount0;
      cost += D[iC][C1] * iCcount1;
      cost += D[iC][C2] * iCcount2;
    }
    ans = min({ans, cost});
  }
  cout << ans << endl;
  return 0;
}