#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 3) {
    cout << "2 5 63" << endl;
    return 0;
  }
  if (n == 4) {
    cout << "2 5 20 63" << endl;
    return 0;
  }
  if (n == 5) {
    cout << "2 5 20 30 63" << endl;
    return 0;
  }
  vector<int> ans;
  ll sum = 0;
  rep(i, 30001) {
    if (i > 1 && (i%2 == 0 || i%3 == 0)) {
      ans.push_back(i);
      sum += i;
    }
    if (ans.size() == n)
      break;
  }
  auto it = ans.begin();
  if (sum%6 == 2) {
    while (*it != 8)
      it++;
    ans.erase(it);
    for (int i = ans.back()+1; i <= 30000; i++) {
      if (i%6 == 0) {
        ans.push_back(i);
        break;
      }
    }
  } else if (sum%6 == 3) {
    while (*it != 9)
      it++;
    ans.erase(it);
    for (int i = ans.back()+1; i <= 30000; i++) {
      if (i%6 == 0) {
        ans.push_back(i);
        break;
      }
    }
  } else if (sum%6 == 5) {
    while (*it != 9)
      it++;
    ans.erase(it);
    for (int i = ans.back()+1; i <= 30000; i++) {
      if (i%6 == 4) {
        ans.push_back(i);
        break;
      }
    }
  }
  rep(i, ans.size()) {
    if (i)
      cout << ' ';
    cout << ans[i];
  }
  cout << endl;
  return 0;
}