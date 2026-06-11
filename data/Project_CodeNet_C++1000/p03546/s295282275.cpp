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
  ll cost[10][10];
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> cost[i][j];
    }
  }
  vector<vector<ll>> A(H);
  ll a;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a;
      A[i].push_back(a);
    }
  }
  vector<ll> min_cost(10);
  min_cost[1] = 0;
  for (int i = 0; i < 10; i++) {
    if (i == 1) continue;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
    vector<vector<bool>> memo(10, vector<bool>(10, false));
    q.push({0, i});
    ll min_c = INF;
    while (!q.empty()) {
      ll cur_pos = q.top().second;
      ll cur_cost = q.top().first;
      q.pop();
      if (cur_pos == 1) {
        min_c = min(min_c, cur_cost);
        continue;
      }
      for (int j = 0; j < 10; j++) {
        if (!memo[cur_pos][j] && j != cur_pos) {
          memo[cur_pos][j] = true;
          q.push({cur_cost + cost[cur_pos][j], j});
        }
      }
    }
    min_cost[i] = min_c;
  }
  ll ans = 0;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (0 <= A[i][j]) ans += min_cost[A[i][j]];
    }
  }
  cout << ans << endl;
  return 0;
}