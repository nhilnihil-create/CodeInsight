#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
using namespace std;
int main() {
  ll n, y, x_s, y_s, z_s;
  cin >> n >> y;
  x_s = y / 10000;

  rep(x_s, n + 1) {
    rep(y_s, n - x_s + 1) {
      z_s = n - x_s - y_s;
      if (z_s >= 0) {
        if (x_s + y_s + z_s == n &&
            10000 * x_s + 5000 * y_s + z_s * 1000 == y) {
          cout << x_s << " " << y_s << " " << z_s << endl;
          return 0;
        }
      }
    }
  }
  cout << "-1 -1 -1" << endl;
}