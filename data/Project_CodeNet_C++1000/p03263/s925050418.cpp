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

int main() {
  // ios_base::sync_with_stdio(0), c
  cout << fixed << setprecision(15);

  ll h, w;
  cin >> h >> w;

  vP ops;
  ll add = 0;
  vll lcs(h);
  rep(i, h) {
    add = 0;
    rep(j, w) {
      ll a;
      cin >> a;
      if(j == w-1) {
        lcs[i] = (a + add) & 1;
        continue;
      };
      a += add;
      if (a & 1) {
        ops.emplace_back(i, j);
        add = 1;
      } else {
        add = 0;
      }
    }
  }

  vP ops2;
  add = 0;
  rep(i, h-1){
    ll a = lcs[i] + add;
    if(a & 1){
      ops2.emplace_back(i, w-1);
      add = 1;
    } else {
      add = 0;
    }
  }

  ll n1 = ops.size();
  ll n2 = ops2.size();
  cout << n1 + n2 << endl;
  rep(i, n1){
    ll y, x;
    tie(y, x) = ops[i];
    printf("%lld %lld %lld %lld\n", y+1, x+1, y+1, x+2);
  }
  rep(i, n2){
    ll y, x;
    tie(y, x) = ops2[i];
    printf("%lld %lld %lld %lld\n", y+1, x+1, y+2, x+1);
  }


  return 0;
}
