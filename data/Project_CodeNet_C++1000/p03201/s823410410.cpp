#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], b[maxn], vis[maxn];
int n, m, ans;
int main() 
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1, greater<int>());
	for(int k = 30; k; --k)
	{
		for(int i = 1, j = n; i < j; )
		{
			if(a[i] + a[j] == (1 << k))
			{
				++ans;
				vis[i] = vis[j] = k;
				++i; 
				--j;
			}
			else if(a[i] + a[j] < (1 << k))
				--j;
			else
				++i;
		}
		m = 0;
		for(int i = 1; i <= n; ++i)
			if(vis[i] != k)
				b[++m] = a[i];
		n = m;
		for(int i = 1; i <= n; ++i)
			a[i] = b[i];
	}
	printf("%d\n", ans);
	return 0;
}