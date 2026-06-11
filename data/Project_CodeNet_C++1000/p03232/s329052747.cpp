#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int maxn = 100100;

const int p = 1e9 + 7;
inline int add(const int a, const int b)
{
  ll z = 0ll + a + b;
  if (z >= p) z -= p;
  return z;
  return (0ll + a + b) % p;
}
inline int mul(const int a, const int b)
{
  ll z = 1ll * a * b;
  z -= z / p * p;
  return z;
  return (1ll * a * b) % p;
}

struct jsum
{
  int s[maxn];
  int qow(int a, int x)
  {
    int ret = 1;
    while (x)
    {
      if (1 & x) ret = mul(ret, a);
      a = mul(a, a);
      x >>= 1;
    }
    return ret;
  }
  jsum(void)
  {
    s[0] = 0;
    for (int i = 1; i < maxn; i++)
    {
      int d = qow(i, p - 2);
      s[i] = add(s[i - 1], d);
    }
  }
  int operator[](const unsigned pos) const { return s[pos]; }
}S;
struct fact
{
  int f[maxn];
  fact(void)
  {
    f[0] = 1;
    for (int i = 1; i < maxn; i++)
    {
      f[i] = mul(f[i - 1], i);
    }
  }
  int operator[](const unsigned pos) const { return f[pos]; }
}f;

int main(void)
{
  int N;
  int ans = 0;
  scanf("%d", &N);
  for (int i = 1; i <= N; i++)
  {
    int Ai;
    scanf("%d", &Ai);
    int d = add(add(S[i], S[N - i + 1]), p - 1);
    ans = add(ans, mul(Ai, d));
  }
  printf("%d\n", mul(ans, f[N]));
  return 0;
}
