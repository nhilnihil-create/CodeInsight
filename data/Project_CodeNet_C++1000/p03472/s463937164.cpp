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
  ll n, h;
  cin >> n >> h;
  vector <pair <ll, ll>> v(n, pair <ll, ll> ());
  rep(i, n) {
    ll a, b;
    cin >> a >> b;
    v.at(i) = make_pair(a, -b);
  }
  sort(v.begin(), v.end());
  pair <ll, ll> p = v.at(n-1);
  p.second = -p.second;
  vector <ll> b(n-1);
  rep(i, n-1) b.at(i) = -v.at(i).second;
  sort(b.begin(), b.end());
  reverse(b.begin(), b.end());
  ll res = 0;
  rep(i, n-1) {
    if (h > 0) {
      if (h <= p.second) {
        h = 0;
        res++;
      } else if (p.first <= b.at(i)) {
        h -= b.at(i);
        res++;
      }
    }
  }
  if (h > 0) {
    if (h-p.second > 0) {
      h -= p.second;
      res++;
      if (h%p.first) res += h/p.first + 1;
      else res += h/p.first;
    } else res++;
  }
  cout << res << endl;
}