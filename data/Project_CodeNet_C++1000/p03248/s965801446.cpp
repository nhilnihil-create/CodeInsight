#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int n = s.size();
  if (s[0] == '0' || s.back() == '1') {
    cout << -1 << endl;
    return 0;
  }
  rep (i, (n-1)/2) {
    if (s[i] != s[n-2-i]) {
      cout << -1 << endl;
      return 0;
    }
  }
  int p = 1;
  for (int i = 2; i <= n; i++) {
    cout << p << ' ' << i << endl;
    if (s[i-2] == '1')
      p = i;
  }
  return 0;
}