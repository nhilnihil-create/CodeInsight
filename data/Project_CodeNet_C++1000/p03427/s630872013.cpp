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
  int n = s.size(), nine = 0;
  rep(i, 1, n) if (s[i] == '9') nine++;
  if (n - 1 == nine)
    cout << (s[0] - '0') + (n - 1) * 9 << endl;
  else
    cout << (s[0] - '0') - 1 + (n - 1) * 9 << endl;
}
