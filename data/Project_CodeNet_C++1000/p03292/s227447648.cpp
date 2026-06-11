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

  vector<int> v(3);
  cin >> v[0] >> v[1] >> v[2];

  int max_val = *max_element(v.begin(), v.end());
  int min_val = *min_element(v.begin(), v.end());

  cout << max_val - min_val << endl;
}
