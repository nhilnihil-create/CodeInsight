#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n; cin >> n;
  set <ll> s;
  rep(i, n) {
    ll a; cin >> a;
    s.insert(a);
  }
  cout << s.size() << endl;
}