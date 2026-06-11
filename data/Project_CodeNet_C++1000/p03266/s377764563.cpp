#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N, K, ans;
  cin >> N >> K;
  if (K % 2 == 0) {
    ll x, y;
    x = N / K;
    y = (N * 2 / K) - (N / K);
    ans = x * x * x + y * y * y;
  } else {
    ll z;
    z = N / K;
    ans = z * z * z;
  }
  cout << ans << endl;
}
