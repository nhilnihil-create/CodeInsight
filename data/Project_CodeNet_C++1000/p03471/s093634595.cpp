#include <iostream>

using namespace std;

int main() {
  int N, Y;
  cin >> N >> Y;
  for (int x = 0; x <= N; ++x) {
    for (int y = 0; y <= N - x; ++y) {
      auto z = N - x - y;
      if (Y == x * 10000 + y * 5000 + z * 1000) {
        cout << x << " " << y << " " << z << endl;
        return 0;
      }
    }
  }
  cout << "-1 -1 -1" << endl;
}
