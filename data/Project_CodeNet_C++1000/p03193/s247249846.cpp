#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n, h, w; cin >> n >> h >> w;
  ll res = 0;
  rep(i, n) {
    ll a, b; cin >> a >> b;
    if (a>=h && b>=w) res++;
  }
  cout << res << endl;
}