// review

#include <iostream>

using namespace std;

int a, b;

bool shouldDrawWhite(int x, int y) {
  if (y < 50) {
    if (a == 0) {
      return false;
    }
    if (y % 2 == 0 && x % 2 == 0) {
      a--;
      return true;
    }
    return false;
  }
  if (b == 0) {
    return true;
  }
  if (y % 2 == 1 && x % 2 == 0) {
    b--;
    return false;
  }
  return true;
}

void solve() {
  a--;b--;
  cout << 100 << " " << 100 << endl;
  for (int y=0;y<100;y++) {
    for (int x=0;x<100;x++) {
      if (shouldDrawWhite(x, y)) {
        cout << '.';
      } else {
        cout << '#';
      }
    }
    cout << endl;
  }
}

int main() {
  cin >> a >> b;
  solve();
}
