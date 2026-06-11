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
  cin >> s;

  int n = (int)s.size();
  if (s[0] != 'A') {
    cout << "WA" << endl;
    return 0;
  }

  int tc = 0;
  int cok = false;
  rep(i, 1, n) {
    if (isupper(s[i]))
      tc++;
    if (i >= 2 && i <= n - 2) {
      if (s[i] == 'C')
        cok = true;
    }
  }

  if (cok && tc == 1)
    cout << "AC" << endl;
  else
    cout << "WA" << endl;
}
