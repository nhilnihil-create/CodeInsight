#include <cmath>
#include <cstdio>
#include <limits>
#include <tuple>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <numeric>
#include <string>
#include <array>
#include <iomanip>
#include <set>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i, n) for (int i = n-1; i >= 0; --i)
#define REP(i, s, n) for (int i = s; i< (int)(n); ++i)
#define all(x) x.begin(), x.end()

using namespace std;
using ll = long long;
ll inf = ll(1e18);
using ll1d = vector<ll>;
using ll2d = vector<ll1d>;
using ll3d = vector<ll2d>;

void solve(istream &ccin = cin, ostream &ccout = cout) {
  ll n;
  ccin >> n;
  string s;
  ccin >> s;
  ll m = 1;
  rep(i, n) {
    m *= 2;
  }
  vector<map<string, ll>> vmp(n + 1);
  rep(i, m) {
    ll jk = 1;
    string sr = "";
    string sb = "";
    rep(j, n) {
      if (i & jk) {
        sr.push_back(s[j]);
      } else {
        sb.push_back(s[j]);
      }
      jk *= 2;
    }
    reverse(all(sb));
    string ss = sr;
    ss.append(sb);
    ++vmp[sr.size()][ss];
  }
  vector<map<string, ll>> vmp2(n + 1);
  rep(i, m) {
    ll jk = 1;
    string sr = "";
    string sb = "";
    rep(j, n) {
      if (i & jk) {
        sr.push_back(s[n + j]);
      } else {
        sb.push_back(s[n + j]);
      }
      jk *= 2;
    }
    reverse(all(sb));
    string ss = sb;
    ss.append(sr);
    ++vmp2[sb.size()][ss];
  }
  ll ans = 0;
  rep(i, n + 1) {
    for (const auto &j :vmp[i]) {
      ans += j.second * vmp2[i][j.first];
    }
  }

  ccout << ans << endl;
}

int main() {
  ios::sync_with_stdio(false);
  solve();
  return 0;
}