#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int N, A, B, C;
vector<int> l;
int dfs(int n, int a, int b, int c, int total) {
  if (n == N) {
    if (a == 0 || b == 0 || c == 0)
      return 1e9;
    return abs(A - a) + abs(B - b) + abs(C - c) + total - 30;
  }

  int x1 = dfs(n + 1, a + l[n], b, c, total + 10);
  int x2 = dfs(n + 1, a, b + l[n], c, total + 10);
  int x3 = dfs(n + 1, a, b, c + l[n], total + 10);
  int x4 = dfs(n + 1, a, b, c, total);
  return min({x1, x2, x3, x4});
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> A >> B >> C;
  l.resize(N);

  rep(i, 0, N) cin >> l[i];
  int ans = dfs(0, 0, 0, 0, 0);
  cout << ans << endl;
}
