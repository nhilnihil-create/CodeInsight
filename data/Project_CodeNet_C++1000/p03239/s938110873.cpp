#include <iostream>

using namespace std;

int main() {
  int N, T;
  cin >> N >> T;
  int cost = 10001;
  for (int n = 0; n < N; ++n) {
    int c, t;
    cin >> c >> t;
    if (t <= T) {
      cost = min(cost, c);
    }
  }
  if (cost <= 1000) {
    cout << cost << endl;
  } else {
    cout << "TLE" << endl;
  }

  return 0;
}
