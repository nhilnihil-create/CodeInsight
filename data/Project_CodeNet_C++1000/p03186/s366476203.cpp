#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
#include <limits>
#include <math.h>
#include <string>
#include <map>

using namespace std;
typedef long long ll;

int main() {
  ll a, b, c;
  cin >> a >> b >> c;
  if (b >= c) {
    cout << b + c << endl;
    return 0;
  }

  ll ans = b * 2;
  c -= b;
  if (c > a) {
    ans += a + 1;
  } else {
    ans += c;
  }
  cout << ans << endl;
  return 0;
}
