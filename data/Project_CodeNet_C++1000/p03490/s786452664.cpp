#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <functional>

using namespace std;
using lli = long long int;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n) 
{ v = vector<T>(n); for (lli i=0; i<n; ++i) cin >> v[i]; }
template<class T, class U> void read_n(vector<pair<T, U>>& v, size_t n)
{ v = vector<pair<T, U>>(n); 
  for (lli i=0; i<n; ++i) cin >> v[i].first >> v[i].second; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

string s;
lli n, p[2], dx = 0;
vector<lli> vp[2];
bool dp[2][40001];
int main() {
  cin >> s >> p[0] >> p[1];
  n = s.size();
  lli i = 0;
  for (; i<n && s[i]=='F'; ++i) ++dx;
  p[0] -= dx;
  lli v = 0;
  lli f = 0;
  for (; i<n; ++i) {
    if (s[i] == 'T') {
      if (v>0) vp[f].push_back(v);
      v = 0;
      f = (f+1)&1;
    } else {
      v++;
    }
  }
  if (v>0) vp[f].push_back(v);
  bool res = true;
  for (lli f=0; f<=1; ++f) {
    for (lli i=0; i<=1; ++i) fill(&dp[i][0], &dp[i][40000], false);
    dp[0][20000] = true;
    lli i = 0;
    for (; i<vp[f].size(); ++i) {
      fill(&dp[(i+1)&1][10000], &dp[(i+1)&1][30000], false);
      for (lli j=10000; j<=30000; ++j) {
	if (dp[i&1][j]) {
	  dp[(i+1)&1][j + vp[f][i]] = true;
	  dp[(i+1)&1][j - vp[f][i]] = true;
	}
      }
    }
    if (!dp[i&1][p[f]+20000]) res = false;
  }
  auto ans = res ? "Yes" : "No";
  cout << ans << endl;
  return 0;
}
