#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;

  double ans = 0;
  for (int i = 1; i <= n; i++) {
    double p = 1;
    int x = i;
    while (x < k) {
      p *= 0.5;
      x *= 2;
    }
    ans += p / n;
  }

  cout << fixed << setprecision(14);
  cout << ans << endl;

  return 0;
}