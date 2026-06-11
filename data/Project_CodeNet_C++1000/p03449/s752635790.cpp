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
  ll N;
  cin >> N;
  vector<vector<ll>> A(2, vector<ll>(N));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < N; j++) {
      cin >> A[i][j];
    }
  }
  queue<pair<ll, pair<ll, ll>>> q;
  q.push({0, {0, 0}});
  ll ans = 0;
  while (!q.empty()) {
    ll x = q.front().second.first;
    ll y = q.front().second.second;
    ll score = q.front().first + A[x][y];
    // cout << x << "," << y << "," << score << endl;
    q.pop();
    if (x == 1 && y == N - 1) {
      ans = max(ans, score);
      continue;
    }
    if (x + 1 < 2) q.push({score, {x + 1, y}});
    if (y + 1 < N) q.push({score, {x, y + 1}});
  }
  cout << ans << endl;
  return 0;
}