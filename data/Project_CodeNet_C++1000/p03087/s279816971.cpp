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

  int n, q;
  string s;
  cin >> n >> q >> s;

  vector<int> check(n, 0);
  rep(i, 1, n) {
    if (s[i - 1] == 'A' && s[i] == 'C')
      check[i] = check[i - 1] + 1;
    else
      check[i] = check[i - 1];
  }

  while (q--) {
    int l, r;
    cin >> l >> r;
    l--, r--;
    cout << check[r] - check[l] << endl;
  }
}
