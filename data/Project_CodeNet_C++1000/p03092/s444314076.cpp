#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
const int N = 5005;
const int inf = 1e18;
int n, a[N], f[N], p[N], A, B, s[N];
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = (x << 3) + (x << 1) + (ch ^ 48); ch = getchar();}
	return x * f;
}
signed main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);
	n = read(); A = read(); B = read();
	for(int i = 1; i <= n; i ++) a[i] = read();
	for(int i = 1; i <= n; i ++) f[i] = inf;
	for(int i = 1; i <= n; i ++)
	{
		int x = a[i];
		for(int j = 0; j <= n; j ++)
		{
			if(j) p[j] = min(f[j], p[j - 1]);
			else p[j] = f[j];
		}
		for(int j = 0; j <= x; j ++) f[j] += A;
		for(int j = x + 1; j <= n; j ++) f[j] += B;
		f[x] = min(f[x], p[x]);
	}
	int ans = inf;
	for(int i = 0; i <= n; i ++) ans = min(ans, f[i]);
	printf("%lld\n", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
