#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
#define rg register
#define LL long long
#define __space putchar(' ')
#define __endl putchar('\n')
template <typename qwq> inline void read(qwq &x)
{
	x = 0;
	rg int f = 1;
	rg char c = getchar();
	while (c < '0' || c > '9')
	{
		if (c == '-') f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
	{
		x = (x << 1) + (x << 3) + (c ^ 48);
		c = getchar();
	}
	x *= f;
}
template <typename qaq> inline void print(qaq x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}
#define int LL 
const int p = 998244353;
const int maxn = 500005;
inline LL Pow(LL x, LL y)
{
	rg LL ret = 1;
	while (y)
	{
		if (y & 1) ret = ret * x % p;
		x = x * x % p;
		y >>= 1;
	}
	return ret;
}
LL fac[maxn];
inline LL C(int n, int m)
{
	return fac[n] * Pow(fac[m], p - 2) % p * Pow(fac[n - m], p - 2) % p;
}
LL n, a, b, k, ans;
signed main()
{
	read(n), read(a), read(b), read(k);
	fac[0] = 1;
	for (rg int i = 1; i <= n; ++i) fac[i] = fac[i - 1] * i % p; 
	for (rg int i = 0; i <= n && i <= k / a; ++i)
	{
		rg LL sum_a = a * i;
		rg LL sum_b = k - sum_a;
		if (sum_b % b) continue;
		sum_b /= b;
		if (sum_b > n) continue;
		ans = (ans + C(n, i) * C(n, sum_b)) % p;
	}
	print(ans);
	return 0;
}