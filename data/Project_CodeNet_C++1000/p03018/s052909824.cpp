#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  string s;
  cin >> s;

  auto replace = [&](int i) {
    s[i] = 'B';
    s[i + 1] = 'C';
    s[i + 2] = 'A';
  };

  int na = 0;
  ll ans = 0;
  int l = s.length();
  rep(i, l - 2) {
    if (s.substr(i, 3) == "ABC") {
      replace(i);
      ans += na + 1;
      i++;
    } else if (s[i] == 'A') {
      na++;
    } else {
      na = 0;
    }
  }
  cout << ans << endl;
}
