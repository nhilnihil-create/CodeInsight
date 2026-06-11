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

  int x;
  cin >> x;
  vector<bool> v(1001, false);
  v[1] = true;
  rep(i, 2, 51) {
    int a = i * i;
    while (a <= 1000) {
      v[a] = true;
      a *= i;
    }
  }

  repr(i, 1, x + 1) {
    if (v[i]) {
      cout << i << endl;
      return 0;
    }
  }
}
