#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  map <int, int> have;
  for (int x : a) ++have[x];
  int ans = 0;
  for (int d = (1 << 30); d >= 1; d /= 2) {
    for (int x : a) {
      if (have.count(d - x) && x != d - x && have[x] != 0 && have[d - x] != 0) {
        int can = min(have[x], have[d - x]);
        ans += can;
        have[x] -= can;
        have[d - x] -= can;
      }
    }
  }
  for (int d = (1 << 30); d >= 1; d /= 2) {
    for (int x : a) {
      if (have.count(d - x) && x == d - x && have[x] > 1) {
        int can = have[x] / 2;
        ans += can;
        have[x] -= 2 * can;
      }
    }
  }
  cout << ans << '\n';
}

