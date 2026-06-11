#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n; cin >> n;
  vector<int> h(n);
  rep(i,n) cin >> h[i];

  int ans = 0;
  while (true) {
    if (*max_element(h.begin(), h.end()) == 0) break;

    int i = 0;
    while (i < n) {
      if (h[i] == 0) i++;
      else {
        ans++;
        while (i < n && h[i] > 0) {
          h[i]--;
          i++;
        }
      }
    }
  }
  cout << ans << endl;
}