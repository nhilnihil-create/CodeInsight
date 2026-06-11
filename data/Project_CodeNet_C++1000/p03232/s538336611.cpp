#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define debug(...) fprintf(stderr, __VA_ARGS__)
inline char nc()
{
	return getchar();
	static char buf[100000], * l = buf, * r = buf;
	if(l == r) r = (l = buf) + fread(buf, 1, 100000, stdin);
	if(l == r) return EOF;
	return *l++;
}
template<class T> void readin(T & x)
{
	x = 0; int f = 1, ch = nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x *= f;
}
const int mod = 1e9 + 7;
long long quick_power(long long x, long long y)
{
	long long res = 1;
	while(y)
	{
		if(y & 1) res = res * x % mod;
		x = x * x % mod;
		y >>= 1;
	}
	return res;
}
int n, a[100050];
int f[100050], g[100050], h[100050];
void solve()
{
	f[0] = 1;
	g[0] = 0;
	for(int i = 1; i <= n; i++)
	{
		f[i] = 1ll * f[i - 1] * i % mod;
		g[i] = (1ll * g[i - 1] * (i + 1) % mod + f[i]) % mod;
	}
	h[n] = quick_power(f[n], mod - 2);
	for(int i = n - 1; ~ i; i--)
	{
		h[i] = 1ll * h[i + 1] * (i + 1) % mod;
	}
	for(int i = 1; i <= n; i++)
	{
		g[i] = 1ll * g[i] * f[n] % mod * h[i + 1] % mod;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans += 1ll * ((f[n] + g[i - 1]) % mod + g[n - i]) % mod * a[i] % mod;
		ans %= mod;
	}
	cout << ans << endl;
}
int main()
{

	readin(n);
	for(int i = 1; i <= n; i++)
	{
		readin(a[i]);
	}
	solve();
	return 0;
}
