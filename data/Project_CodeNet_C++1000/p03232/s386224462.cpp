#include <cstdio>
#include <iostream>

using namespace std;

const int mod = 1'000'000'007;

int add(int a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
  return a;
}

int mul(int a, int b) {
  return (int)((long long)a * b % mod);
}

const int N = 100'009;

int a[N];
int f[N];
int rf[N];
int s[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  f[0] = 1;
  for (int i = 1; i < n; ++i) {
    f[i] = mul(f[i - 1], i);
  }
  rf[n + 1] = 1;
  for (int i = n; i >= 2; --i) {
    rf[i] = mul(rf[i + 1], i);
  }
  s[0] = 0;
  for (int i = 1; i <= n; ++i) {
    s[i] = add(s[i - 1], mul(f[i - 1], rf[i + 1]));
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans = add(ans, mul(a[i], add(add(s[i + 1], s[n - i]), mod - s[1])));
  }
  printf("%d\n", ans);
}
