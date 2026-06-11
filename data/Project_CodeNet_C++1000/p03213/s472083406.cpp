#include <bits/stdc++.h>
using namespace std;

vector<int> get_primes(int n) {
  vector<int> primes;
  primes.push_back(2);
  for (int i=3; i<=n; i+=2) {
    bool ok = true;
    for (int j=3; j<i; j+=2) {
      if (i % j == 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      primes.push_back(i);
    }
  }
  return primes;
}
int main() {
  int n;
  cin>>n;
  map<int, int> m;
  vector<int> primes = get_primes(n);
  for (int i=2; i<=n; i++) {
    int k = i;
    for (int p: primes) {
      while (k % p == 0) {
        ++m[p];
        k /= p;
      }
    }
  }
  int cnt2 = 0, cnt4 = 0, cnt14 = 0, cnt24 = 0, cnt74 = 0;
  for (auto e: m) {
    int v = e.second;
    if (v >= 2) {
      ++cnt2;
    }
    if (v >= 4) {
      ++cnt4;
    }
    if (v >= 14) {
      ++cnt14;
    }
    if (v >= 24) {
      ++cnt24;
    }
    if (v >= 74) {
      ++cnt74;
    }
  }
  int ans = max(cnt4 * (cnt4 - 1) / 2 * (cnt2 - 2), 0)
            + cnt24 * (cnt2 - 1)
            + cnt14 * (cnt4 - 1)
            + cnt74;
  cout<<ans<<endl;

}