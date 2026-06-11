#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int T = 0, X = 0, Y = 0;
  for (int i = 0; i < N; i++) {
    int t, x, y;
    cin >> t >> x >> y;
    int tmp = (t - T) - abs(X - x) - abs(Y - y);
    if (tmp < 0) return cout << "No" << "\n", 0;
    if (tmp % 2) return cout << "No" << "\n", 0;
    T = t, X = x, Y = y;
  }
  cout << "Yes" << "\n";
}