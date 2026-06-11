#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  int t, a; cin >> t >> a;
  vector<int> h(n);
  t *= 1000; a *= 1000;
  int ans = 0, min_d = 1000006;
  rep(i,n) {
    cin >> h[i];
    h[i] *= 6;
    int d = abs(a - (t - h[i]));
    if (d < min_d) {
      min_d = d;
      ans = i+1;
    }
  }
  cout << ans << endl;
  return 0;
}