#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const int INF = 100100100;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> m(N);

  int mi = INF;
  rep(i, 0, N) {
    cin >> m[i];
    mi = min(mi, m[i]);
    X -= m[i];
  }

  int ans = X / mi + N;
  cout << ans << endl;

  return 0;
}
