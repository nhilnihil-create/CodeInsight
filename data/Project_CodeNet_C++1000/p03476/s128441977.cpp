#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


// Sieve of Eratosthenes
// https://youtu.be/UTVg7wzMWQc?t=2774
struct Sieve {
  int n;
  vector<int> f, primes;
  Sieve(int n=1):n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; ++i) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for (ll j = i*i; j <= n; j += i) {
        if (!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x;}
  vector<int> factorList(int x) {
    vector<int> res;
    while (x != 1) {
      res.push_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorList(x);
    if (fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
};

int main() {
  int m = 100000;
  Sieve sieve(m);
  vector<int> s;
  for(int x=1;x<=m;x+=2) {
    if(sieve.isPrime(x) && sieve.isPrime((x+1)/2)) s.push_back(x);
  }
  vector<ll> ans;
  int q;
  cin >> q;
  rep(i,q) {
    int l, r;
    cin >> l >> r;

    auto litr = lower_bound(s.begin(), s.end(), l);
    auto ritr = upper_bound(s.begin(), s.end(), r);
    auto index = distance(litr, ritr);
    ans.push_back(index);
  }

  rep(i, q) {
    cout << ans[i] << endl;
  }
  return 0;
}
