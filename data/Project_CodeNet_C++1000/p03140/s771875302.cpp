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
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
  int n;
  string a, b, c;
  cin >> n >> a >> b >> c;
  int ans = 0;
  rep(i, n) {
    int same = 0;
    if (a[i] == b[i])
      same++;
    if (b[i] == c[i])
      same++;
    if (c[i] == a[i])
      same++;
    if (!same)
      ans += 2;
    else if (same == 1)
      ans++;
  }
  cout << ans << endl;
  return 0;
}