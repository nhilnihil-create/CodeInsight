#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

ull sum[200005] = {0};
ull n, x;

ull solve();

int main() {
  cin >> n >> x;
  for(ull i = 1; i <= n; ++i) {
    ull a;
    cin >> a;
    sum[i] = sum[i - 1] + a;
  }
  cout << solve() << endl;
  return 0;
}

ull solve() {
  ull ans = 0;
  for(ull i = 1; i <= n; ++i) {
    ull now = n, j = 1, nans = 0;
    while(1) {
      if(j == 1)
        nans += sum[now] * 5;
      else if(j >= 2)
        nans += sum[now] * (2 * j + 1);
      now -= i;
      if(now == 0 || now > n) break;
      if(j == 1)
        nans -= sum[now] * 5;
      else if(j >= 2)
        nans -= sum[now] * (2 * j + 1);
      ++j;
    }
    nans += x * (n + i);
    if(i == 1) ans = nans;
    ans = min(nans, ans);
  }
  return ans;
}