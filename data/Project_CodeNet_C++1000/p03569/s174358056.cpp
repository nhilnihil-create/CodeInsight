#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

bool is_palindrome(string s) {
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] != s[n - i - 1])
      return false;
  }

  return true;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  cin >> s;

  int n = s.size();
  int ans = 0, l = 0, r = n - 1;
  while (l < r) {
    if (s[l] == s[r]) {
      l++;
      r--;
    } else if (s[l] == 'x') {
      l++;
      ans++;
    } else if (s[r] == 'x') {
      r--;
      ans++;
    } else {
      cout << -1 << endl;
      return 0;
    }
  }

  cout << ans << endl;
}