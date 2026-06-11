#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> a(n);
  const int INF = 10e8;
  int ans = INF;
  rep(i,n) cin >> a[i];
  rep(i,n) {
    if (a[i] % 2 == 1) {
      ans = 0;
      break;
    }

    int cnt = 0;
    while (a[i] % 2 != 1) {
      a[i] /= 2;
      cnt++;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;
  return 0;
}