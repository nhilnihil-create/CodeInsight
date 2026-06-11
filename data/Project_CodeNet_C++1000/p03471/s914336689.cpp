#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, Y, yen_10000 = -1, yen_5000 = -1, yen_1000 = -1;
  cin >> N >> Y;

  for (int a = 0; a <= N; a++) {
    for (int b = 0; a + b <= N; b++) {
      int c = N - a - b;
      int sum = 10000 * a + 5000 * b + 1000 * c;
      if (sum == Y) {
        yen_10000 = a;
        yen_5000 = b;
        yen_1000 = c;
      }
    }
  }

  cout << yen_10000 << ' ' << yen_5000 << ' ' << yen_1000 << endl;
}