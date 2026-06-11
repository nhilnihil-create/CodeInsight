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

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll n;
  cin >> n;

  vll cnt(13, 0);
  cnt[0]++;
  rep(i, n) {
    ll x;
    cin >> x;
    cnt[x]++;
  }

  ll ans = 0;
  rep(i, 1 << 14) {
    ll tmp = 12;
    vll lst;
    rep(j, 13) {
      if (cnt[j] == 1) {
        if (i >> j & 1) {
          ll jp = (24 - j)%24;
          lst.push_back(jp);
        } else {
          lst.push_back(j);
        }
      } else if (cnt[j] == 2) {
        lst.push_back(j);
        lst.push_back(24 - j);
      } else if(cnt[j] >= 3) {
        cout << 0 << endl;
        return 0;
      }
    }
    ll m = lst.size();
    repLRE(ii, 0, m - 2) {
      repLRE(jj, ii + 1, m - 1) {
        ll now = abs(lst[ii] - lst[jj]);
        chmin(now, 24 - now);
        chmin(tmp, now);
      }
    }
    chmax(ans, tmp);
  }  // i

  cout << ans << endl;

  return 0;
}
