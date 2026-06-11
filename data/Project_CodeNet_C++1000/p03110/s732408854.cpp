#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
  int n;
  double ans = 0;
  cin >> n;
  for (int i = 0; i < n; ++i ) {
    double x;
    string u;
    cin >> x >> u;
    if (u == "JPY")
      ans += x;
    else
      ans += x * 380000;
  }
  cout << fixed << setprecision(10) << ans << endl;
}
