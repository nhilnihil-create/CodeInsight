#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  int Y;
  cin >> N >> Y;
  Y /= 1000;
  bool ok = true;
  if (N * 10 < Y || N > Y) {
    cout << "-1 -1 -1" << endl;
  }
  else {
    for (int i = N; i >= 0; i--) {
      int memo;
      for (int j = (N - i); j >= 0; j--) {
        memo = 10 * i + 5 * j + (N - i - j);
        if (memo == Y) {
          cout << i << " " << j << " " << (N - i - j) << endl;
          ok = false;
          break;
        }
      }
      if (ok == false) {
        break;
      }
      if (i == 0) {
        cout << "-1 -1 -1" << endl;
      }
    }
  }
}
