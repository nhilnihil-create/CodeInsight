#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
int ctoi(char c) {
  if (c >= '0' && c <= '9') {
    return c - '0';
  }
  return 0;
}
ll factorial(ll n) {
  if (n == 1) {
    return 1;
  }
  ll ans = factorial(n-1);
  return ans*n;
}
ll gcd(ll a, ll b) {
  if (b == 0) return a;
  return gcd(b, a%b);
}
ll lcm(ll a, ll b) {
  return (a/gcd(a, b))*b;
}
bool is_prime(ll n) {
  for (ll i = 2; i*i <= n; i++) {
    if (n%i == 0) return false;
  }
  return n != 1;
}
ll mod_pow(ll x, ll n, ll mod) {
  if (n == 0) return 1;
  ll res = mod_pow(x*x%mod, n/2, mod);
  if (n & 1) res = res * x % mod;
  return res;
}

int main() {
  ll n, m, q;
  cin >> n >> m >> q;
  vector <vector <ll>> v(n, vector <ll> ());
  rep(i, m) {
    ll l, r;
    cin >> l >> r;
    ll dis = r-l;
    v.at(l-1).push_back(dis);
  }
  rep(i, n) sort(v.at(i).begin(), v.at(i).end());
  rep(i, q) {
    ll l, r;
    cin >> l >> r;
    ll res = 0;
    for (ll j = l-1; j < r; j++) {
      if (v.at(j).size() == 0) continue;
      ll dis = r - j - 1;
      auto itr = upper_bound(v.at(j).begin(), v.at(j).end(), dis);
      res += distance(v.at(j).begin(), itr);
    }
    cout << res << endl;
  }
}