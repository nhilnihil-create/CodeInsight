#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> t(n+1), x(n+1), y(n+1);
  rep(i,n) cin >> t[i+1] >> x[i+1] >> y[i+1];

  string ans;
  for (int i=1;i<=n;i++) {
    int dt = t[i] - t[i-1];
    int dx = abs(x[i] - x[i-1]);
    int dy = abs(y[i] - y[i-1]);
    int d = dx + dy;
    //printf("%d %d %d %d\n",dt, dx, dy, d);
    if (d <= dt && (dt - d) % 2 == 0) {
      ans = "Yes";
    } else {
      ans = "No";
      break;
    }
  }
  cout << ans << endl;
  return 0;
}