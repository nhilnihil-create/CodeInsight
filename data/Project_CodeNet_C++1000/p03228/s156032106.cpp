#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#define MOD (1000000007l)
#define rep(i, n) for(long i = 0; i < n; i++)

using namespace std;

void solve() {
  long a, b, k;
  cin >> a >> b >> k;
  rep (i, k) {
    if (i % 2 == 0) {
      a /= 2;
      b += a;
    } else {
      b /= 2;
      a += b;
    }
  }
  cout << a << " " << b << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
