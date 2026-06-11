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

  int a, b;
  cin >> a >> b;
  vector<int> tree(1000);
  rep(i, 1, 1001) tree[i] = tree[i - 1] + i;

  int diff = b - a;
  int ans = 0;
  rep(i, 1, 1001) {
    if (diff == tree[i] - tree[i - 1]) {
      cout << tree[i] - b << endl;
      return 0;
    }
  }
}
