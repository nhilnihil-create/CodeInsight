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
  int a, b, k;
  cin >> a >> b >> k;
  int cnt = 1;
  int ans = 0;
  int sm = a <= b ? a : b;
  for (int i = sm; i >= 1; i--) {
    if (a % i == 0 && b % i == 0) {
      if (k == cnt++) {
        ans = i;
        break;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
