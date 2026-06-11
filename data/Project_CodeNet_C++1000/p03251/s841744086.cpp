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

  int n, m, X, Y;
  cin >> n >> m >> X >> Y;
  vector<int> x(n), y(m);
  rep(i, 0, n) cin >> x[i];
  rep(i, 0, m) cin >> y[i];

  int x_max = *max_element(x.begin(), x.end());
  int y_min = *min_element(y.begin(), y.end());
  if (X < y_min && y_min <= Y && x_max < y_min)
    cout << "No War" << endl;
  else
    cout << "War" << endl;
}
