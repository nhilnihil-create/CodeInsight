#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

using ll = long long;
using P = pair<int, int>;

vector<bool> eratos(ll n) {
  vector<bool> primes(n + 1, true);
  primes[0] = primes[1] = false;
  for (ll i = 2; i * i <= n; i++) {
    if (primes[i]) {
      ll j = i + i;
      while (j <= n) {
        primes[j] = false;
        j += i;
      }
    }
  }
  return primes;
}

// 素数か判定する
bool isPrime(ll n) {
  if (n <= 1) {
    return false;
  }
  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  int q;
  cin >> q;
  vector<P> lr(q);
  rep(i, q) {
    int l, r;
    cin >> l >> r;
    lr.at(i) = make_pair(l, r);
  }
  const int MAX = 100'000;
  vector<bool> e = eratos(MAX);
  // 2017に似た数の累積和
  vector<int> s(MAX + 1, 0);
  for (int i = 1; i <= MAX; i++) {
    if (i % 2 == 0) {
      s.at(i) = s.at(i - 1);
      continue;
    }
    if (i == 1) {
      s.at(i) = 0;
      continue;
    }
    if (isPrime(i) && isPrime((i + 1) / 2)) {
      s.at(i) = s.at(i - 2) + 1;
    } else {
      s.at(i) = s.at(i - 2);
    }
  }
  rep(i, q) {
    P x = lr.at(i);
    int l = x.first;
    int r = x.second;
    cout << (s.at(r) - s.at(l - 1)) << endl;
  }
  return 0;
}
