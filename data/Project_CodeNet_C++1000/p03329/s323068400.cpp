#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

template<class T> inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template<class T> inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

const ll INF = 1LL << 60;

int main() {
  int n;
  cin >> n;
  int ans = n;
  rep(i, n + 1) {
    int cnt = 0;
    int t = i;
    while (t) {
      cnt += t % 6;
      t /= 6;
    } 
    t = n - i;
    while (t) {
      cnt += t % 9;
      t /= 9;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}
