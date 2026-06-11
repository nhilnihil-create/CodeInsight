#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  ll n, m, d;
  cin >> n >> m >> d;
  double ans = 0;
  if(d > 0) {
    ans = (double)max((ll)0, n - 2 * d) * (m - 1) * 2.0 / (n * n) +
          2.0 * d * (m - 1) * 1.0 / (n * n);
  } else {
    ans = (double)n * (m - 1) * 1.0 / (n * n);
  }

  printf("%.10f\n", ans);
  return 0;
}