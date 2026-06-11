#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repI(i, d, n) for (int i = (d); i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
using M = map<int, int>;
ll INF = 1ll<<61;
double pi = 3.141592653589793238;

int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll sum = accumulate(a.begin(), a.end(), 0);

  bitset<(ll)5e6> dp;
  dp[0] = 1;
  rep(i, n) {
    dp |= (dp << a[i]);
  }

  repI(i, (sum+1)/2, sum+1) {
    if (dp[i]) {
      cout << i << endl;
      break;
    }
  }

  return 0;
}
