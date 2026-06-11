#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <algorithm>
#include <cassert>
#include <cfloat>
#include <complex>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
#define rep(i, n) for (ll i = 0; i < (n); ++i)
#define repLRE(i, l, r) for (ll i = (l); i <= (r); ++i)
#define rrepLRE(i, l, r) for (ll i = (l); i >= (r); --i)
#define Sort(v) sort(v.begin(), v.end())
#define rSort(v) sort(v.rbegin(), v.rend())
#define Reverse(v) reverse(v.begin(), v.end())
#define Lower_bound(v, x) \
  distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) \
  distance(v.begin(), upper_bound(v.begin(), v.end(), x))

using ll = long long;
using ull = unsigned long long;
using P = pair<ll, ll>;
using T = tuple<ll, ll, ll>;
using vll = vector<ll>;
using vP = vector<P>;
using vT = vector<T>;
using vvll = vector<vector<ll>>;
using vvP = vector<vector<P>>;
using dqll = deque<ll>;

ll dx[9] = {-1, 1, 0, 0, -1, -1, 1, 1, 0};
ll dy[9] = {0, 0, -1, 1, -1, 1, -1, 1, 0};

/* Macros reg. ends here */

const ll INF = 1LL << 50;

ll n;

ll proc(vector<string>& mp, ll cy, ll cx) {
  ll ans = 0;
  ll st = 0;
  while (cx <= n - 1 && cy <= n - 1) {
    bool ok = true;
    if (st == 0) {
      repLRE(i, 1, n - 1) {
        rep(j, i) {
          if (mp[cy + j][cx + i] != mp[cy + i][cx + j]) {
            ok = false;
            cx = cx + i + 1, cy = cy + i + 1;
            st = 0;
            break;
          }
        }
        if (!ok) break;
      }
      if (ok) {
        st = 1, ans++, cx++, cy++;
      }
    } else {
      rep(j, n - 1) {
        if (mp[cy + j][cx + n - 1] != mp[cy + n - 1][cx + j]) {
          ok = false;
          cx = cx + n, cy = cy + n;
          st = 0;
          break;
        }
      }
      if (ok) {
        st = 1, ans++, cx++, cy++;
      }
    }
  }
  return ans;
}

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  cin >> n;

  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }

  vector<string> mp(2 * n);
  rep(i, n) {
    cin >> mp[i];
    mp[i] += mp[i];
    mp[n + i] = mp[i];
  }

  ll ans = 0;
  repLRE(i, 0, n - 1) {
    ll cy = 0, cx = i;
    ans += proc(mp, cy, cx);
  }

  repLRE(i, 1, n - 1) {
    ll cy = i, cx = 0;
    ans += proc(mp, cy, cx);
  }

  cout << ans << endl;
}
