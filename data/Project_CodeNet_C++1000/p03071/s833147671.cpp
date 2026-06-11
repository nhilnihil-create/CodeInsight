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
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = 0; i < 2; i++) {
    if (a >= b) {
      ans += a;
      --a;
    }
    else {
      ans += b;
      --b;
    }
  }
  cout << ans << endl;

  return 0;
}
