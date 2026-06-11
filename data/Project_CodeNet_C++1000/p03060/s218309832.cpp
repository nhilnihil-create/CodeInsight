#include <bits/stdc++.h>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
using namespace std;
using ll = long long;
using GraphI = vector<vector<int>>;
using GraphC = vector<vector<char>>;
using pint = pair<int, int>;

int main() {
  int N;
  cin >> N;
  vector<int> V(N), C(V);
  rep(i, 0, N) cin >> V[i];
  rep(i, 0, N) cin >> C[i];

  int ans = 0;
  rep(bit, 0, 1 << N) {
    int x = 0;
    int y = 0;
    rep(i, 0, N) {
      if (bit >> i & 1) {
        x += V[i];
        y += C[i];
      }
    }

    ans = max(ans, x - y);
  }

  cout << ans << endl;

  return 0;
}
