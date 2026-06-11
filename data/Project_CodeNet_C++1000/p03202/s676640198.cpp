#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#define dumpv(...)
#endif

#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int MOD = 1e9 + 7;
const int INF = 1001001001;
const ll LINF = 1001002003004005006ll;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n + 1);
  a[0] = 0;
  rep(i, n) cin >> a[i + 1];
  dump(n, a);
  map<int, int> mp;
  function<int(int)> check = [&](int k) {
    dump(k);
    mp.clear();
    for (int i = 1; i <= n; i++) {
      if (i == 1) mp[a[i] - 1] = 0;
      if (a[i - 1] < a[i]) {
        // 何もしない
      } else {
        // auto it = mp.lower_bound(a[i]);
        auto it = mp.upper_bound(a[i] - 1);
        mp.erase(it, mp.end());
        int j = a[i] - 1;
        if (k == 1) {
          j = -1;
        } else {
          while (mp[j] + 1 >= k) {
            mp[j] = 0;
            j--;
          }
        }
        if (0 <= j) {
          mp[j] += 1;
        } else {
          dump("false", mp);
          return false;
        }
      }
      dump(mp);
    }
    return true;
  };
  int ans = 0;
  // for (int k = 1; k < n; k++) {
  //   if (check(k)) {
  //     ans = k;
  //     break;
  //   }
  // }
  // index=0が条件を満たすこともあるので、leftの初期値は-1
  int left = 0;
  // index=a.size()-1が条件を満たさないこともあるので、rightの初期値はa.size()
  int right = n;
  while (right - left > 1) {
    int mid = left + (right - left) / 2;
    if (check(mid))
      right = mid; // 例えば(key<=a[mid])など
    else
      left = mid;
  }
  ans = min(n, right);
  // leftは条件を満たさない最大の値、rightは条件を満たす最小の値になっている
  dump(ans);
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
  // freopen("temp.1", "r", stdin);
  solve();
  return 0;
}