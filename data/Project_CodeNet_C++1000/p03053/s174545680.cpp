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
  vector<string> A(H);
  vector<vector<ll>> D(H, vector<ll>(W, INF));
  for (int i = 0; i < H; i++) {
    cin >> A[i];
  }
  queue<pair<ll, ll>> q;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (A[i][j] == '#') {
        q.push({i, j});
        D[i][j] = 0;
      }
    }
  }
  int step_x[4] = {0, 0, 1, -1};
  int step_y[4] = {1, -1, 0, 0};
  while (!q.empty()) {
    ll cur_x = q.front().first;
    ll cur_y = q.front().second;
    q.pop();
    for (int i = 0; i < 4; i++) {
      ll next_x = cur_x + step_x[i];
      ll next_y = cur_y + step_y[i];
      if (next_x < 0 || next_x >= H || next_y < 0 || next_y >= W) continue;
      if (D[next_x][next_y] != INF) continue;
      D[next_x][next_y] = D[cur_x][cur_y] + 1;
      q.push({next_x, next_y});
    }
  }
  ll ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      ans = max(ans, D[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}