#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll a, b; cin >> a >> b;
  if (a%2) {
    bitset <50> s(a);
    rep(i, (b-a)%4) {
      bitset <50> tmp(b-i);
      s = s ^ tmp;
    }
    ll res = 0;
    rep(i, 50) {
      if (s.test(i)) res += (ll)pow(2, i);
    }
    cout << res << endl;
  } else {
    bitset <50> s(0);
    rep(i, (b-a+1)%4) {
      bitset <50> tmp(b-i);
      s = s ^ tmp;
    }
    ll res = 0;
    rep(i, 50) {
      if (s.test(i)) res += (ll)pow(2, i);
    }
    cout << res << endl;
  }
}