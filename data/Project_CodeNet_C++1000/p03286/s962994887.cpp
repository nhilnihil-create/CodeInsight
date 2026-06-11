/*
 * atcoder/abc105_2nd/c.cpp
 */

// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }
template <class T> bool chmax(T &a, T b) { if (a < b) {a = b; return true; } return false; }

// -9
// 1  0 0 1
// 4 -2 1 0
ll N;
void solve() {
  cin >> N;
  if (N == 0) {
    cout << 0 << endl;return;
  }
  string s = "";
  while (N) {
    ll r = N % -2;
    if (r<0) r+=2;
    s += to_string(r);
    N = (N-r) / -2;
  }
  reverse(s.begin(), s.end());
  cout << s << endl;
}
int main() {
  // cout.precision(15); cout << fixed;

  solve();

  return 0;
}
