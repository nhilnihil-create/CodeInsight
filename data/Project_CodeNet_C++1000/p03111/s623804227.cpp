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

ll n, a, b, c;
vll ls;
ll ans = INF;
void dfs(vll& as, vll& bs, vll& cs, ll asum, ll bsum, ll csum, ll d){
  if(d == n){
    if(as.empty() || bs.empty() || cs.empty()) return;
    ll tmp = 0;
    tmp += max(0LL, ((ll)as.size() - 1))*10;
    tmp += abs(a - asum);
    tmp += max(0LL, ((ll)bs.size() - 1))*10;
    tmp += abs(b - bsum);
    tmp += max(0LL, ((ll)cs.size() - 1))*10;
    tmp += abs(c - csum);
    chmin(ans, tmp);
    return;
  }
  as.push_back(ls[d]);
  dfs(as, bs, cs, asum + ls[d], bsum, csum, d+1);
  as.pop_back();
  bs.push_back(ls[d]);
  dfs(as, bs, cs, asum, bsum + ls[d], csum, d+1);
  bs.pop_back();
  cs.push_back(ls[d]);
  dfs(as, bs, cs, asum, bsum, csum + ls[d], d+1);
  cs.pop_back();
  dfs(as, bs, cs, asum, bsum, csum, d+1);
}

int main() {
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  cin >> n >> a >> b >> c;

  ls.resize(n);
  rep(i, n) cin >> ls[i];

  vll as, bs, cs;
  dfs(as, bs, cs, 0, 0, 0, 0);

  cout << ans << endl;

  return 0;
}
