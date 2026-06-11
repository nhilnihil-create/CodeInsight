#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, t, x, y, i, j, T = 0, X = 0, Y = 0;
  cin >> N;
  string s = "Yes";
  for (i = 0; i < N; i++) {
    cin >> t >> x >> y;
    T = t - T, X = abs(x - X), Y = abs(y - Y);
    if (X + Y > T || (t + x + y) % 2 != 0) {
      s = "No";
      break;
    }
  }
  
  cout << s << endl;
}