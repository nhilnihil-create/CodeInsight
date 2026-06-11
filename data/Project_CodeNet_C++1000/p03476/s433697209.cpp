#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n = 1) : n(n), f(n + 1) {
    f[0] = f[1] = -1;
    for(ll i = 2; i <= n; ++i) {
      if(f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for(ll j = i * i; j <= n; j += i) {
        if(!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x; }
  vector<int> factorList(int x) {
    vector<int> res;
    while(x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorList(x);
    if(fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for(int p : fl) {
      if(res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};

int main() {
  ll n = 1e5 + 1;
  vl a(n);
  Sieve s(1e5 + 1);
  rep2(i, 1, n) {
    if(i % 2 == 0) continue;
    if(s.isPrime(i) && s.isPrime((i + 1) / 2)) a[i] = 1;
  }
  vl cum(n + 1, 0);
  rep(i, n) cum[i + 1] = cum[i] + a[i];
  ll q;
  cin >> q;
  rep(i, q) {
    ll l, r;
    cin >> l >> r;
    cout << cum[r + 1] - cum[l] << '\n';
  }
}