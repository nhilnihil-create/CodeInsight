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
  vector<ll> x(N), y(N), h(N);
  for (int i = 0; i < N; i++) {
    cin >> x[i] >> y[i] >> h[i];
  }
  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      set<ll> s;
      set<pair<ll, ll>> zero_heights;
      ll H;
      for (int k = 0; k < N; k++) {
        if (h[k] == 0) {
          zero_heights.insert({x[k], y[k]});
          continue;
        }
        H = h[k] + abs(x[k] - i) + abs(y[k] - j);
        s.insert(H);
      }
      if (s.size() == 1) {
        bool succ = true;
        for (auto e : zero_heights) {
          if (H - abs(e.first - i) - abs(e.second - j) > 0) succ = false;
        }
        if (succ) {
          cout << i << " " << j << " " << H << endl;
          return 0;
        }
      }
    }
  }
  return 0;
}