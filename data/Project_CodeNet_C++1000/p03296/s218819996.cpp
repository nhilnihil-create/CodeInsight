#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 10;
int n;
int a[maxn], f[maxn][2];
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a[i]);
		f[i][0] = f[i - 1][1];
		f[i][1] = min(f[i - 1][0], f[i - 1][1]) + 1;
		if(a[i] != a[i - 1])
			f[i][0] = min(f[i][0], f[i - 1][0]);
	}
	printf("%d\n", min(f[n][0], f[n][1]));
	return 0;
}
		