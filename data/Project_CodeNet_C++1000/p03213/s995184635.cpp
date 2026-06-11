#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1000000007;

long mpow(long a, long b) {
  long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

long com(long n, long r) {
  if (n < r || n < 0 || r < 0) return 0;
  long x = 1, y = 1;
  for (int i = 1; i <= r; i++) {
    x = x * (n - i + 1) % MOD;
    y = y * i % MOD;
  }
  return x * mpow(y, MOD - 2) % MOD;
}

map<long, int> MA;

void pf(long n) {
  for (long i = 2; i * i <= n; i++) {
    while (n % i == 0) MA[i]++, n /= i;
  }
  if (n != 1) MA[n]++;
}

int main() {
  int N;
  cin >> N;
  for (int i = 1; i <= N; i++) pf(i);
  int c75 = 0, c25 = 0, c15 = 0, c5 = 0, c3 = 0;
  for (auto ma : MA) {
    if (ma.second >= 74) c75++;
    else if (ma.second >= 24) c25++;
    else if (ma.second >= 14) c15++;
    else if (ma.second >= 4) c5++;
    else if (ma.second >= 2) c3++;
  }
  int ans = 0;
  ans += com(c75, 1);
  ans += com(c75 + c25, 1) * com((c75 + c25 - 1) + c15 + c5 + c3, 1);
  ans += com(c75 + c25 + c15, 1) * com((c75 + c25 + c15 - 1) + c5, 1);
  ans += com(c75 + c25 + c15 + c5, 2) * com((c75 + c25 + c15 + c5 - 2) + c3, 1);
  cout << ans << "\n";
}