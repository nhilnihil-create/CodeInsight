#include <bits/stdc++.h>
using namespace std;

long long n;
vector<long long> a;
bitset<4000001> dp;

long long solve();

int main() {
  cin >> n;
  a.resize(n);
  for(int i = 0; i < n; ++i) cin >> a[i];
  cout << solve() << endl;
  return 0;
}

long long solve() {
  long long sum = 0;
  dp[0] = 1;
  for(int i = 0; i < n; ++i) {
    dp |= dp << a[i];
    sum += a[i];
  }
  for(int i = ++sum / 2;; ++i)
    if(dp[i]) return i;
}
