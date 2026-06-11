#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

int main() {
  int N, D, X, a;
  cin >> N >> D >> X;
  rep(i, 0, N) {
    cin >> a;
    // 切り上げ
    int b = (D + (a - 1)) / a;
    X += b;
  }

  cout << X << endl;

  return 0;
}
