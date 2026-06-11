#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;

  vector<long long> a(n), b(n), c(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n) cin >> c[i];
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  sort(c.begin(), c.end());

  long long ans = 0;
  rep(i,n) {
    long long k = 0;
    k = lower_bound(a.begin(), a.end(),b[i]) - a.begin();

    long long j = 0;
    j = c.end() -upper_bound(c.begin(), c.end(), b[i]);

    ans += k * j;
  }

  cout << ans << endl;

}