#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t H, W, D, Q, a, l, r;
  cin >> H >> W >> D;
  map<int, pair<int, int>> mp;
  vector<vector<int64_t>> A(H + 1, vector<int64_t>(W + 1));
  for (int i = 1; i <= H; i++)
  {
    for (int j = 1; j <= W; j++)
    {
      cin >> a;
      mp[a] = make_pair(i, j);
      A.at(i).at(j) = a;
    }
  }
  cin >> Q;
  vector<pair<int64_t, int64_t>> lr(Q);
  for (int i = 0; i < Q; i++)
  {
    cin >> l >> r;
    lr.at(i) = make_pair(l, r);
  }
  vector<int64_t> dp(H * W + 1, -1);
  for (int i = 1; i <= H * W; i++)
  {
    if (i - D <= 0)
    {
      dp[i] = 0;
      continue;
    }
    int x = abs(mp.at(i - D).first - mp.at(i).first) + abs(mp.at(i - D).second - mp.at(i).second);
    dp[i] = dp[i - D] + x;
  }
  for (int i = 0; i < Q; i++)
  {
    tie(l, r) = lr.at(i);
    cout << dp[r] - dp[l] << endl;
  }
}
