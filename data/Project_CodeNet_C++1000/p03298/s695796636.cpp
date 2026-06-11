#include <algorithm>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f, MOD = 1000000007;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*-----------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  string s; cin >> s;
  vector<pair<string, string> > sec;
  for (int mask = 0; mask < (1 << n); ++mask) {
    string red = "", blue = "";
    REP(i, n) {
      if ((mask >> i) & 1) red += s[n + i];
      else blue += s[n + i];
    }
    reverse(ALL(red));
    reverse(ALL(blue));
    sec.emplace_back(blue, red);
  }
  sort(ALL(sec));
  long long ans = 0;
  for (int mask = 0; mask < (1 << n); ++mask) {
    string red = "", blue = "";
    REP(i, n) {
      if ((mask >> i) & 1) red += s[i];
      else blue += s[i];
    }
    ans += upper_bound(ALL(sec), make_pair(red, blue)) - lower_bound(ALL(sec), make_pair(red, blue));
  }
  cout << ans << '\n';
  return 0;
}
