#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  int ans = 0;
  rep(i, n) {
    int t = a[i];
    while (t % 2 == 0) {
      t /= 2;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
