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
  // ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(15);

  ll m, k;
  cin >> m >> k;

  if (m == 0) {
    if (k == 0) {
      cout << "0 0" << endl;
    } else {
      cout << "-1" << endl;
    }
    return 0;
  }

  if (m == 1) {
    if (k == 0) {
      cout << "0 0 1 1" << endl;
    } else {
      cout << "-1" << endl;
    }
    return 0;
  }

  ll tail = (1LL << m) - 1;
  if(k > tail){
    cout << "-1" << endl;
    return 0;
  }

  if(k == 0){
    repLRE(i, 0, tail) cout << i << " " << i << ((i == tail)? "\n" : " ");
    return 0;
  }

  vll ansv;
  ansv.push_back(0);
  ansv.push_back(k);
  ansv.push_back(0);
  repLRE(i, 1, tail) if (i != k) ansv.push_back(i);
  ansv.push_back(k);
  rrepLRE(i, tail, 1) if (i != k) ansv.push_back(i);

  rep(i, (ll)ansv.size()) cout << ansv[i] << ((i == (ll)ansv.size()-1)? "\n" : " ");

  return 0;
}
