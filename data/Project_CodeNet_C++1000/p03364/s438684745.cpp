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
  int n;
  cin >> n;
  vector<string> s(n);
  rep(i, n) cin >> s[i];
  int ans = 0;
  rep(i, n) {
    bool flag = true;
    rep(j, n) {
      rep(k, j) {
        if (s[j][(i+k)%n] != s[k][(i+j)%n]) {
          flag = false;
          break;
        }
      }
      if (!flag)
        break;
    }
    if (flag)
      ans++;
  }
  ans *= n;
  cout << ans << endl;
  return 0;
}