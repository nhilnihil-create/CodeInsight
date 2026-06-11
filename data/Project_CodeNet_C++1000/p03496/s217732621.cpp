#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
#define REP(var, a, b) for (int var = (a); var < (b); var++)
#define rep(var, n) for (int var = 0; var < (n); ++var)
#define ALL(c) (c).begin(), (c).end()
#define rALL(c) (c).rbegin(), (c).rend()
ll MOD = 1000000007;
const ll INF = 1LL << 62;

int main() {
  //
  ll n;
  cin >> n;
  vl a(n);
  ll m = INT_MAX, M = INT_MIN;
  ll mi = -1, Mi = -1;
  rep(i, n) {
    cin >> a[i];
    if (m > a[i]) {
      m = a[i], mi = i;
    }
    if (M < a[i]) {
      M = a[i], Mi = i;
    }
  }
  vector<pll> op;
  if (M < 0) {
    for (int i = n - 1; i > 0; i--) {
      if (a[i - 1] > a[i]) {
        a[i - 1] += a[i];
        op.push_back({i, i - 1});
      }
    }
  } else if (m > 0) {
    rep(i, n - 1) {
      if (a[i] > a[i + 1]) {
        a[i + 1] += a[i];
        op.push_back({i, i + 1});
      }
    }
  } else {
    //
    if (abs(m) > abs(M)) {
      rep(i, n) {
        a[i] += a[mi];
        op.push_back({mi, i});
      }
      for (int i = n - 1; i > 0; i--) {
        if (a[i - 1] > a[i]) {
          a[i - 1] += a[i];
          op.push_back({i, i - 1});
        }
      }
    } else {
      rep(i, n) {
        a[i] += a[Mi];
        op.push_back({Mi, i});
      }
      rep(i, n - 1) {
        if (a[i] > a[i + 1]) {
          a[i + 1] += a[i];
          op.push_back({i, i + 1});
        }
      }
    }
  }

  cout << op.size() << endl;
  for (auto& o : op) {
    cout << o.first + 1 << " " << o.second + 1 << endl;
  }
  return 0;
}
