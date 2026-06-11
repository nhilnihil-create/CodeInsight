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
 
const ll Inf = 1e18;
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, x;
  cin >> n >> x;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  vector <ll> pref(n + 1);
  for (int i = 0; i < n; ++i) pref[i + 1] = pref[i] + a[i];
 
  auto get = [&] (int l, int r) {
    return pref[r + 1] - pref[l];
  };
 
  ll ans = Inf;
  for (int gs = 1; gs <= n; ++gs) {
    ll cost = 0; 
    int cnt = 0;
    for (int i = n - 1; i >= 0; i -= gs, ++cnt) {
      ll sm = get(max(0, i - gs + 1), i);
      if (cnt == 0) {
        cost += 5 * sm;
      } else {
        cost += (2 * (cnt + 1) + 1) * sm;
      } 
      cost = min(cost, Inf);
    }
    cost += (ll)n * x;
    cost += (ll)gs * x;
    ans = min(ans, cost);
  }
  cout << ans << '\n';
}
 
