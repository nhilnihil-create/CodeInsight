#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
#include <bitset>
 
using namespace std;
using ll = long long;
 
int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> vec(n);
  for (auto &v : vec)
    cin >> v;
 
  ll x_best = 0;
  ll score_best = accumulate(vec.begin(), vec.end(), 0LL);
  for (ll i = 63LL; 0LL <= i; --i) {
    bitset<64> bset = x_best;
    bset.set(i);
    ll x = bset.to_ulong();
    if (k < x)
      continue;
    ll score = 0;
    for (auto &v : vec)
      score += x ^ v;
    if (score_best < score) {
      score_best = score;
      x_best = x;
    }
  }
  cout << score_best << endl;
}
