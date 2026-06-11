#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n,m;
  cin >> n >> m;

  vector<ll> x(n), y(n), z(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i] >> z[i];
  }

  ll ans = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        vector<ll> sum(n);

        for (int l = 0; l < n; l++) {
          if(i == 0) {
            sum[l] += x[l];
          } else {
            sum[l] -= x[l];
          }

          if(j == 0) {
            sum[l] += y[l];
          } else {
            sum[l] -= y[l];
          }

          if(k == 0) {
            sum[l] += z[l];
          } else {
            sum[l] -= z[l];
          }
        }

        sort(sum.rbegin(),sum.rend());
        ll tmp = 0;

        for (int l = 0; l < m; l++) {
          tmp += sum[l];
        }
        ans = max(ans, tmp);
      }
    }
  }

  cout << ans << '\n';
}