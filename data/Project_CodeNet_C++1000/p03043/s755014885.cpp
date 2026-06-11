#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;
const ll INF = 1001001001;

int main() {
  long double n, k;
  cin >> n >> k;

  long double pr = 0;
  for (ll i = 1; i <= n; i++) {
    long double res = 1 / n;
    ll j = i;
    while (j < k) {
      res *= 0.5;
      j *= 2;
    }
    pr += res;
    // cout << pr << " ";
  }
  cout << fixed << setprecision(10) << pr;

  return 0;
}
