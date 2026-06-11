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
  ll n, m;
  cin >> n >> m;
  vector <pair <ll, ll>> v(m, pair <ll, ll> ());
  map <ll, ll> score;
  map <pair <ll, ll>, ll> tmp;
  vector <pair <ll, ll>> u(m, pair <ll, ll> ());
  rep(i, m) {
    ll a, b;
    cin >> a >> b;
    pair <ll, ll> p = make_pair(a, b);
    v.at(i) = p;
    u.at(i) = p;
  }
  sort(u.begin(), u.end());
  rep(i, m) {
    if (score.count(u.at(i).first)) {
      score.at(u.at(i).first)++;
      tmp[u.at(i)] = score.at(u.at(i).first);
    } else {
      score[u.at(i).first] = 1;
      tmp[u.at(i)] = 1;
    }
  }
  rep(i, m) {
    ll p = v.at(i).first, x = tmp.at(v.at(i));
    string s = to_string(p), t = to_string(x);
    rep(j, 6-s.size()) cout << 0;
    cout << p;
    rep(j, 6-t.size()) cout << 0;
    cout << x << endl;
  }
}