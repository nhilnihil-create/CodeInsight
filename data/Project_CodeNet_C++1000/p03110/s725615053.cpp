#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  double res = 0;
  for (int i = 0; i < N; ++i) {
    double v;
    string s;
    cin >> v >> s;
    if (s == "JPY") res += v;
    else res += v * 380000.0;
  }
  cout << fixed << setprecision(10) << res << endl;
}