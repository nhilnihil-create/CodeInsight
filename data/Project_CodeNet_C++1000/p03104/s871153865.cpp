#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define chmin(a, b) a = min(a, b)
#define chmax(a, b) a = max(a, b)
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

ll xor_under_n_odd(ll n) { return (n + 1) / 2 % 2; }
ll xor_under_n(ll n) {
  if (n % 2 == 1) {
    return xor_under_n_odd(n);
  } else {
    return xor_under_n_odd(n + 1) ^ (n + 1);
  }
}

int main() {
  ll a, b;
  cin >> a >> b;
  cout << (xor_under_n(a - 1) ^ xor_under_n(b)) << endl;
}