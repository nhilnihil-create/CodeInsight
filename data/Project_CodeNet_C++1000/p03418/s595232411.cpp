#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;

  ll ans = 0;
  for (int i = 1; i <= N; ++i) {
    int p = N / i;
    int r = N % i;
    int n = max(0, i - 1 - K + 1);
    int m = max(0, r - K + 1);
    ans += (ll)p * n + m;
  }

  if (K == 0)
    ans -= N;
  cout << ans << endl;
}