#include <iostream>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  int H, W, D;
  cin >> H >> W >> D;
  unordered_map<int, pair<int, int>> map;
  rep(i, H) rep(j, W) {
    int A;
    cin >> A;
    map[A] = {i, j};
  }
  vector<int> SUM(H * W + 1, 0);
  for (int i = 1; i <= H * W - D; ++i) {
    int next = i + D;
    int x1, x2, y1, y2;
    tie(x1, y1) = map[i];
    tie(x2, y2) = map[next];
    int cost = abs(x2 - x1) + abs(y2 - y1);
    SUM[next] = SUM[i] + cost;
  }

  int Q;
  cin >> Q;
  rep(i, Q) {
    int L, R;
    cin >> L >> R;
    int answer = SUM[R] - SUM[L];
    cout << answer << endl;
  }
  return 0;
}