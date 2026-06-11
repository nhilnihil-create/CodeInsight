#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>
#include <sstream>
#include <fstream>
#include <climits>
#include <map>
#include <numeric>
#include <functional>
#include <utility>

using namespace std;

#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main(void) {
  int t, x;
  cin >> t >> x;
  double ans = (double)t / x;
  printf("%.5f\n", ans);
  return 0;
}
