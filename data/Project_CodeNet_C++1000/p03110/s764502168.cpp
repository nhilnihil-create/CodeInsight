#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  double ans = 0;
  rep(i, 0, N) {
    double x;
    string u;
    cin >> x >> u;

    if (u == "JPY") {
      ans += x;
    } else {
      double yen = x * 380000.0;
      ans += yen;
    }
  }
  cout << ans << endl;
  return 0;
}
