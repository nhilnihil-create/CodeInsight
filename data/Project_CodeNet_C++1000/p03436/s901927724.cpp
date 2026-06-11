#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;

int main() {
  ll H, W;
  cin >> H >> W;
  vector<string> s(H);
  ll white_sum = 0, black_sum = 0;
  for (int i = 0; i < H; i++) {
    cin >> s[i];
    for (int j = 0; j < W; j++) {
      if (s[i][j] == '#') {
        black_sum++;
      } else {
        white_sum++;
      }
    }
  }
  priority_queue<pair<ll, pair<ll, ll>>> q;
  vector<vector<ll>> memo(H, vector<ll>(W, INF));
  q.push({0, {0, 0}});
  ll min_v = INF;
  bool clear = false;
  while (!q.empty()) {
    auto cost = q.top().first;
    auto pos = q.top().second;
    q.pop();
    if (memo[pos.first][pos.second] < cost) continue;
    ll h = pos.first, w = pos.second;
    if (h + 1 < H && s[h + 1][w] == '.' && cost + 1 < memo[h + 1][w]) {
      q.push({cost + 1, {h + 1, w}});
      memo[h + 1][w] = cost + 1;
    }
    if (0 <= h - 1 && s[h - 1][w] == '.' && cost + 1 < memo[h - 1][w]) {
      q.push({cost + 1, {h - 1, w}});
      memo[h - 1][w] = cost + 1;
    }
    if (w + 1 < W && s[h][w + 1] == '.' && cost + 1 < memo[h][w + 1]) {
      q.push({cost + 1, {h, w + 1}});
      memo[h][w + 1] = cost + 1;
    }
    if (0 <= w - 1 && s[h][w - 1] == '.' && cost + 1 < memo[h][w - 1]) {
      q.push({cost + 1, {h, w - 1}});
      memo[h][w - 1] = cost + 1;
    }
  }
  if (memo[H - 1][W - 1] != INF)
    cout << W * H - memo[H - 1][W - 1] - 1 - black_sum << endl;
  else
    cout << -1 << endl;
  return 0;
}