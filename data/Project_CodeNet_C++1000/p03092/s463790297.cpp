#include<bits/stdc++.h>
#define maxn 5010
#define ll long long
using namespace std;
int a[maxn], pre[maxn][maxn];
ll f[maxn];
int main()
{
	int n, A, B;
	scanf("%d%d%d", &n, &A, &B);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (j >= a[i]) pre[i][j] = pre[i - 1][j] + 1;
			else pre[i][j] = pre[i - 1][j];
	f[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		f[i] = 1e18;
		for (int j = 0; j <= i - 1; j++)
		{
			if (a[j] >= a[i]) continue;
			int t1, t2;
			if (j == 0) t1 = 0;
			else t1 = pre[i - 1][a[j] - 1] - pre[j][a[j] - 1];
			t2 = (i - j - 1) - t1;
			f[i] = min(f[i], f[j] + (ll)t1 * B + (ll)t2 * A);
		}
	}
	ll res = 1e18;
	for (int i = 0; i <= n; i++)
	{
		int t1, t2;
		if (i == 0) t1 = 0;
		else t1 = pre[n][a[i] - 1] - pre[i][a[i] - 1];
		t2 = (n - i) - t1;
		res = min(res, f[i] + (ll)t1 * B + (ll)t2 * A);
	}
	printf("%lld\n", res);
	return 0;
}