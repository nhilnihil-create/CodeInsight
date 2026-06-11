#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

map<ll, int> prime_factor(ll n) {
  map<ll, int> ret;
  for (ll i=2; i*i<=n; i++) {
    while (n%i==0) {
      ret[i]++;
      n /= i;
    }
  }
  if (n!=1) ret[n] = 1;
  return ret;
}


int main() {
  ll N, P, ans = 1;
  cin >> N >> P;
  map<ll, int> memo = prime_factor(P);
  for (auto p: memo) {
    auto key = p.first;
    auto value = p.second;
    value /= N;
    ans *= pow(key, value);
  }
  cout << ans << endl;
}