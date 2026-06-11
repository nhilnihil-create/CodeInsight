#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n, ans;
int p[maxn], pos[maxn], f[maxn];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) 
	{
		scanf("%d", &p[i]);
		pos[p[i]] = i;
	}
	for(int i = n; i; --i)
	{
		if(pos[i + 1] > pos[i])
			f[i] = f[i + 1] + 1;
		else
			f[i] = 1;
	}
	ans = n - f[1];
	for(int i = 1; i <= n; ++i)
		ans = min(ans, n - (p[1] == i) - f[i + 1]);
	printf("%d\n", ans);
	return 0;
}
	