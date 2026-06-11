#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

vector<long long> divisor(long long n) {
  vector<long long> ret;
  for (long long i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n) ret.push_back(n / i);
    }
  }
  sort(ret.begin(), ret.end());  // 昇順に並べる
  return ret;
}

int main() {
  ll n;
  cin >> n;
  ll ans = 0;
  vector<long long> ret = divisor(n);
  for (auto x : ret) {
    ll _n = (n / x) - 1;
    if (_n != 0 && (n / _n == n % _n)) {
      ans += _n;
    }
  }
  cout << ans << endl;
}