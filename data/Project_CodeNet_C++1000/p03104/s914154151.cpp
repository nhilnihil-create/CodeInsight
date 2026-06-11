#include <bitset>
#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

ll hoge(ll x) {
  bitset<64> bset;
  for (ll i = 0; i < 64; ++i) {
    ll a = pow(2LL, i);
    ll b = pow(2LL, i + 1);
    bset.set(i, ((x + 1) / b * a + max(0LL, (x+1) % b - a)) % 2);
  }
  return bset.to_ullong();
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << (hoge(a-1) ^ hoge(b)) << endl;
}