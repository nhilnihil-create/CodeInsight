#include <math.h>

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;
const ll INF = 1001001001;

int main() {
  ll n;
  cin >> n;
  vector<ll> tm(5);
  ll mi = 1001001001001001;

  rep(i, 5) {
    cin >> tm[i];
    mi = min(mi, tm[i]);
  }
  long double n2 = static_cast<long double>(n);
  long double mi2 = static_cast<long double>(mi);

  long double d = n2 / mi2;
  ll ans = 4 + ceil(d);
  cout << ans;
  return 0;
}
