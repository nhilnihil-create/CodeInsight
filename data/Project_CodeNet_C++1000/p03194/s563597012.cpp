#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n, p; cin >> n >> p;
  if (n==1) cout << p << endl;
  else {
    ll res = 1;
    for (ll i = 2; i*i <= p; i++) {
      if (p%i == 0) {
        ll tmp = 0;
        while (p%i == 0) {
          tmp++;
          p /= i;
        }
        if (tmp >= n) res *= (ll)pow(i, (tmp/n));
      }
    }
    cout << res << endl;
  }
}