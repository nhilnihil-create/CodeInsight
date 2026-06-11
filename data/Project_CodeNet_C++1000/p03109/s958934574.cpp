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

  int y, m, d;
  scanf("%d/%d/%d", &y, &m, &d);
  if (y > 2019 || y == 2019 && m >= 5)
    cout << "TBD" << endl;
  else
    cout << "Heisei" << endl;
}
