#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

// -------------------------------------------------------
ll N;

int main() {
  cin >> N;

  string ans = "";
  ll v = 1;

  for (ll i = 0; i <= 40; i++) {
    if (N == 0) {
      break;
    }
    if (N % (2 * abs(v)) != 0) {
      ans = '1' + ans;
      N -= v;
    } else {
      ans = '0' + ans;
    }
    v *= -2;
  }
  if (ans == "") {
    cout << 0 << "\n";
    return 0;
  }

  bool non_zero = false;
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] == '1') {
      non_zero = true;
    }
    if (non_zero) {
      cout << ans[i];
    }
  }
  cout << "\n";
}