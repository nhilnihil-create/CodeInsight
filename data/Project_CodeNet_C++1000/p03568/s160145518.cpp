#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int n;
vector<int> a;
int dfs(int i, bool y) {
  if (i == n) {
    if (y)
      return 1;
    else
      return 0;
  }

  int a1 = dfs(i + 1, y ? y : (a[i] - 1) % 2 == 0);
  int a2 = dfs(i + 1, y ? y : a[i] % 2 == 0);
  int a3 = dfs(i + 1, y ? y : (a[i] + 1) % 2 == 0);
  return a1 + a2 + a3;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  a.resize(n);
  rep(i, 0, n) cin >> a[i];

  cout << dfs(0, false) << endl;
}
