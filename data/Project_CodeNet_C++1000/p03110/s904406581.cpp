#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  double ans = 0;
  while (N--) {
    double x;
    string u;
    cin >> x >> u;
    if (u == "JPY") ans += x;
    else ans += x * 380000;
  }
  cout << fixed << setprecision(5) << ans << "\n";
}