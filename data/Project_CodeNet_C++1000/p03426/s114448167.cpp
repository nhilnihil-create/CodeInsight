#include <iostream>
#include <vector>
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int H, W, D; cin >> H >> W >> D;
  int HW = H * W;
  vector<int> p(HW);
  for (int i = 0; i < HW; i++) {
    int A; cin >> A; A--;
    p[A] = i;
  }

  auto dist = [&](int p1, int p2) {
    return abs(p1 / W - p2 / W) + abs(p1 % W - p2 % W);
  };

  vector<int> cs(HW);
  for (int x = 0; x < D; x++) {
    int y = x;
    for (int y = x; y + D < HW; y += D) {
      cs[y + D] = cs[y] + dist(p[y], p[y + D]);
    }
  }

  int Q; cin >> Q;
  for (int i = 0; i < Q; i++) {
    int L, R; cin >> L >> R; L--; R--;
    cout << cs[R] - cs[L] << "\n";
  }
}