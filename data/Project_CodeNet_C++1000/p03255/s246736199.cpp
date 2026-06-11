#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, shoot;
  cin >> n >> shoot;
  vector<long long> acm(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> acm[i];
    acm[i] += acm[i - 1];
  }
  long long minv = 9e18;
  for (int k = 1; k <= n; k++) {
    long long ret = (long long)(k + n) * shoot;
    long long coef = 3;
    for (int i = n; i > 0 && ret < minv; i -= k, coef += 2) {
      ret += (acm[i] - acm[max(0, i - k)]) * max(coef, 5LL);
    }
    minv = min(minv, ret);
  }
  cout << minv << '\n';
  return 0;
}