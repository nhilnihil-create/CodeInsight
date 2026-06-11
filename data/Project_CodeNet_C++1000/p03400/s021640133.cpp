#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, d, x; cin >> n >> d >> x;
  vector<int> a(n);
  rep(i,n) cin >> a[i];
  int ans = x;

  rep(i,n) {
    int day = 1, b = 1;
    while(day <= d) {
      ans++;
      day = b * a[i] + 1;
      b++;
    }
  }
  cout << ans << endl;
  return 0;
}