#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

inline int read()
{
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=x*10+c-'0';c=getchar();}
	return x*f;
}
const int mod = 1e9 + 7;
const int maxn = 1e5 + 10;
inline int qpow(int x, int y)
{
	int res = 1;
	for(; y; y >>= 1, x = (ll)x * x % mod)
		if(y & 1) res = (ll)res * x % mod;
	return res;
}
int n, a[maxn], inv[maxn], b[maxn];

int main()
{
	n = read();
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	for(int i = 1; i <= n; i ++)
		inv[i] = qpow(i, mod - 2), inv[i] = (inv[i] + inv[i - 1]) % mod;
	int rev = mod - inv[1];
	for(int i = 1; i <= n; i ++)
		b[i] = ((inv[n - i + 1] + inv[i]) % mod + rev) % mod;
	int ans = 0;
	for(int i = 1; i <= n; i ++)
		ans = (ans + (ll)a[i] * b[i] % mod) % mod;
	for(int i = 1; i <= n; i ++)
		ans = (ll)ans * i % mod;
	printf("%d\n", ans);
	return 0;
}
