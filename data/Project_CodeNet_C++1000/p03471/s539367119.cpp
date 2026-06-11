#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n, y; cin >> n >> y;
  bool flag = 1;
  rep(i, n+1) {
    rep(j, n+1-i) {
      ll m = n-i-j;
      if (10000*i+5000*j+1000*m == y) {
        cout << i << ' ' << j << ' ' << m << endl;
        flag = 0;
        break;
      }
    }
    if (!flag) break;
  } 
  if (flag) cout << -1 << ' ' << -1 << ' ' << -1 << endl;
}