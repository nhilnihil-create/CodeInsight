#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k; cin >> n >> k;
  vector<int> h(n);
  rep(i,n) {
    cin >> h[i];
  }
  sort(h.begin(),h.end());
  int dh = 0, cnt = 0, ans = 1e9+5;
  rep(i,n-k+1) {
    dh = h[i+k-1] - h[i];
    ans = min(ans, dh);
  }
  cout << ans << endl;
  return 0;
}