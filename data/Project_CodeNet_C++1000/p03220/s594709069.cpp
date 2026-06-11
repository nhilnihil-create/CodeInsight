#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T, A;
  cin >> N >> T >> A;

  int X;
  double min_abs_num = DBL_MAX;
  double min_abs_i = 1;
  for (int i = 1; i <= N; i++) {
    cin >> X;
    double abs_num = abs((T - X * 0.006) - A);
    if (abs_num < min_abs_num) {
      min_abs_num = abs_num;
      min_abs_i = i;
    }
  }

  cout << min_abs_i << endl;
}