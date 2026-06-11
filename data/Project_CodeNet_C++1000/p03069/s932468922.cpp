#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

const ll MAX = 1e9;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int b = count(s.begin(), s.end(), '#');
  int w = count(s.begin(), s.end(), '.');
  int ans = min(b, w);

  int lb = 0, lw = 0;
  rep(i, n) {
    if (s[i] == '.')
      lw++;
    else
      lb++;
    ans = min(ans, lb + w - lw);
  }
  cout << ans << endl;
}
