#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  string s;
  ll k;
  cin >> s >> k;
  int head_one = 0, next = -1;
  rep(i, 0, (int)s.size()) {
    if (s[i] == '1')
      head_one++;
    else {
      next = (int)(s[i] - '0');
      break;
    }
  }

  if (head_one >= k)
    cout << 1 << endl;
  else
    cout << next << endl;
}
