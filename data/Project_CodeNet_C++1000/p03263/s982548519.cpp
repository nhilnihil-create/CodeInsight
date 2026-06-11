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
ll a[505][505];

int main() {
  ll H, W;
  cin >> H >> W;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      cin >> a[i][j];
    }
  }
  ll cnt = 0;
  vector<pair<pair<ll, ll>, pair<ll, ll>>> q;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W - 1; j++) {
      if (a[i][j] % 2) {
        a[i][j]--;
        a[i][j + 1]++;
        q.push_back({{i, j}, {i, j + 1}});
        cnt++;
      }
    }
  }
  for (int i = 0; i < H - 1; i++) {
    if (a[i][W - 1] % 2) {
      a[i][W - 1]--;
      a[i + 1][W - 1]++;
      q.push_back({{i, W - 1}, {i + 1, W - 1}});
      cnt++;
    }
  }
  cout << cnt << endl;
  for (auto p : q) {
    printf("%d %d %d %d\n", p.first.first + 1, p.first.second + 1,
           p.second.first + 1, p.second.second + 1);
  }
  return 0;
}