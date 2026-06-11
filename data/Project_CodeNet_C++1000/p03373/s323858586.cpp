#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
  int A, B, C, X, Y;
  cin >> A >> B >> C >> X >> Y;
  int ans = 0;
  if (A + B < 2 * C) {
    if (X < Y) {
      ans += X * A + X * B;
    } else {
      ans += Y * A + Y * B;
    }
  } else {
    if (X < Y) {
      ans += X * 2 * C;
    } else {
      ans += Y * 2 * C;
    }
  }
  if (X < Y) {
    if (B < 2 * C) {
      ans += (Y - X) * B;
    } else {
      ans += (Y - X) * 2 * C;
    }
  } else {
    if (A < 2 * C) {
      ans += (X - Y) * A;
    } else {
      ans += (X - Y) * 2 * C;
    }
  }
  cout << ans << endl;
}