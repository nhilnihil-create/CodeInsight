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
  ll h, w, d;
  cin >> h >> w >> d;
  vector <pair <ll, ll>> v(h*w, pair <ll, ll> ());
  rep(i, h) {
    rep(j, w) {
      ll a;
      cin >> a;
      a--;
      v.at(a) = make_pair(i, j);
    }
  }
  vector <ll> u(h*w);
  rep(i, h*w) {
    if (0 <= i-d) {
      u.at(i) = u.at(i-d) + abs(v.at(i).first-v.at(i-d).first) 
        + abs(v.at(i).second-v.at(i-d).second);
    } else {
      u.at(i) = 0;
    }
  }
  ll n;
  cin >> n;
  rep(i, n) {
    ll l, r;
    cin >> l >> r;
    l--; r--;
    cout << u.at(r) - u.at(l) << endl;
  }
}