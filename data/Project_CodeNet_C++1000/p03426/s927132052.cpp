#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
constexpr int mod = 1e9+7;

int main() {
  int h, w, d;
  cin >> h >> w >> d;
  vector<vector<int>> a(h, vector<int>(w));
  rep(i,h) rep(j,w) cin >> a[i][j];
  vector<int> x(h * w + 1), y(h * w + 1);
  rep(i,h) rep(j,w) {
    x[a[i][j]] = i, y[a[i][j]] = j;
  }
  vector<int> cum(h * w + 1, 0);
  for (int i = 0; i <= h * w; i++) {
    if (i - d > 0) {
      cum[i] = cum[i - d] + abs(x[i] - x[i - d]) + abs(y[i] - y[i - d]);
    }
  }

  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << cum[r] - cum[l] << "\n";
  }
  return 0; 
}
