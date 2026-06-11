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
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int m, k;
  cin >> m >> k;
  int lim = 1<<m;
  if (k >= lim || m == 1 && k != 0) {
    cout << -1 << endl;
    return 0;
  }
  if (m == 1) {
    cout << "0 0 1 1" << endl;
    return 0;
  }
  vector<int> ans;
  rep(i, k)
    ans.push_back(i);
  ans.push_back(k);
  for (int i = k-1; i>=0; i--)
    ans.push_back(i);
  for (int i = k+1; i<lim; i++)
    ans.push_back(i);
  ans.push_back(k);
  for (int i = lim-1; i>k; i--)
    ans.push_back(i);
  rep(i, ans.size())
    cout << ans[i] << (i+1<ans.size()?' ':'\n');
  return 0;
}