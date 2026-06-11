#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const ll MAX = 1e9;

int main() {
  string s;
  cin >> s;
  int l = 0;
  int r = s.length() - 1;

  int ans = 0;
  while (l <= r) {
    if (s[l] == s[r]) {
      l++;
      r--;
    } else if (s[l] == 'x') {
      ans++;
      l++;
    } else if (s[r] == 'x') {
      ans++;
      r--;
    } else {
      ans = -1;
      break;
    }
  }
  cout << ans << endl;
}
