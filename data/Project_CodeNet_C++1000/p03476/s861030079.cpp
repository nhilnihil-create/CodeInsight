#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  vector <bool> prime((ll)pow(10, 5), 1);
  prime.at(0) = 0;
  rep(i, (ll)pow(10, 5)) {
    if (prime.at(i)) {
      for (ll j = 2*(i+1)-1; j < (ll)pow(10, 5); j += i+1) prime.at(j) = 0;
    }
  }
  vector <ll> prime_2017((ll)pow(10, 5)+1, 0);
  for (ll i = 1; i <= (ll)pow(10, 5); i++) {
    if (i%2 && prime.at(i-1) && prime.at((i+1)/2-1)) prime_2017.at(i) = 1;
  }
  rep(i, (ll)pow(10, 5)) prime_2017.at(i+1) += prime_2017.at(i);
  ll q; cin >> q;
  rep(i, q) {
    ll l, r; cin >> l >> r;
    cout << prime_2017.at(r)-prime_2017.at(l-1) << endl;
  }
}