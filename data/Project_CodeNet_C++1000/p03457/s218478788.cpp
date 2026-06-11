#include <iostream>

using namespace std;

int main() {
  int N, t, x, y, T{}, X{}, Y{};
  cin >> N;
  bool cond{true};
  for (int i = 0; i != N; ++i) {
    cin >> t >> x >> y;
    auto d = abs(X - x) + abs(Y - y);
    if (T + d > t || (t - T - d) % 2) {
      cond = false;
      break;
    }
    X = x, Y = y, T = t;
  }
  cout << (cond ? "Yes" : "No") << endl;
}
