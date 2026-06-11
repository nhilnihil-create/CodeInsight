#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  double n, k; cin >> n >> k;
  int c = 1;
  double ans = 0;
  for (int i = n; i>0; i--) {
    while (i*c<k) {
      c*=2;
    }
    ans += 1.0 / (n*c);
  }
  cout << fixed << setprecision(10);
  cout << ans << endl;
  return 0;
}