#include <bits/stdc++.h>
#define REP(i, a, n) for (ll i = ((ll) a); i < ((ll) n); i++)
using namespace std;
typedef long long ll;

int main(void) {
  ll H, W, N;
  cin >> H >> W >> N;
  vector<ll> X(N), Y(N);
  REP(i, 0, N) cin >> X[i] >> Y[i];

  vector<vector<ll>> y(H + 1);
  REP(i, 0, N) {
    y[X[i]].push_back(Y[i]);
  }

  ll yy = 1;
  REP(x, 2, H + 1) {
    bool ok = true;
    REP(i, 0, y[x].size()) {
      if (y[x][i] <= yy) {
        cout << x - 1 << endl;
        return 0;
      } else if (y[x][i] == yy + 1) {
        ok = false;
      }
    }
    if (ok) {
      yy++;
    }
  }
  cout << H << endl;
}