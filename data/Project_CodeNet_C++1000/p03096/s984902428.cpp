#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 2e5 + 10;
int n, tot;
int c[maxn];
ll f[maxn], sumf[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		int val;
		scanf("%d", &val); 
		if(tot && c[tot] == val)
			--tot;
		c[++tot] = val;
	}
	f[0] = 1;
	for(int i = 1; i <= tot; ++i)
	{
		f[i] = (sumf[c[i]] + f[i - 1]) % mod;
		sumf[c[i]] += f[i - 1];
	}
	printf("%lld\n", f[tot]);
	return 0;
}