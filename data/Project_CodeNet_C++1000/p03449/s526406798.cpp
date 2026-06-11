#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> a1(n), a2(n);
  int c1 = 0, c2 = 0, ans = 0;
  rep(i,n) {cin >> a1[i]; }
  rep(i,n) {cin >> a2[i]; c2 += a2[i]; }
  ans = 0;
  rep(i,n) {
    c1 += a1[i];
    if (i!=0) c2 -= a2[i-1];
    ans = max(ans, c1 + c2);
  }
  cout << ans << endl;
  return 0;
}