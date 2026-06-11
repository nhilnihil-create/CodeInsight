#include <iostream>
using namespace std;
int main() {
  int N, Y;
  cin >> N >> Y;

  bool exit = false;

  for (int x = 0; x <= N; ++x) {
    for (int y = 0; y <= N; ++y) {
      int z = N - x - y;
      if (z < 0)
        break;
      int sum = 10000 * x + 5000 * y + 1000 * z;
      if (sum == Y) {
        cout << x << " " << y << " " << z << endl;
        exit = true;
        break;
      }
    }
    if (exit) {
      break;
    }
  }
  if (!exit) {
    cout << "-1 -1 -1" << endl;
  }
}