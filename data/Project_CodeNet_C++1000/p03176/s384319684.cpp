#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) x&(-x)
typedef long long ll;
const int maxn = 2e5+3;
ll C[maxn];
int n, h[maxn], a[maxn];
void add(int x, ll d)
{
	while (x<=n)
	{
		C[x] = max(C[x], d);
		x += lowbit(x);
	}
}
ll ma(int x)
{
	ll maxs = 0;
	while (x)
	{
		maxs = max(C[x], maxs);
		x -= lowbit(x);
	}
	return maxs;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", h+i);
	for (int i = 1; i <= n; ++i)
		scanf("%d", a+i);
	for (int i = 1; i <= n; ++i)
		add(h[i], ma(h[i]-1)+a[i]);
	printf("%lld\n", ma(n));
	return 0;
}
/*
4
3 1 4 2
10 20 30 40

60
*/