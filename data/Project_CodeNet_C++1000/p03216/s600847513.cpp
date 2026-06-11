#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MXN = 1e6 + 10;

char s[MXN];
int a[MXN], c[MXN], la, lc;
int sum[MXN];
ll csum[MXN];


int main ()
{
	int n;
	scanf("%d", &n);
	scanf("%s", s);
	sum[0] = 0;
	la = lc = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'D')
			a[++la] = i;
		else if (s[i] == 'C')
			c[++lc] = i;
		if (s[i] == 'M')
			sum[i + 1] = sum[i] + 1;
		else
			sum[i + 1] = sum[i];
	}
	csum[0] = 0;
	for (int i = 1; i <= lc; i++)
	{
		csum[i] = csum[i - 1] + 1ll * sum[c[i]];
	}
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int d;
		scanf("%d", &d);
		ll ans = 0;
		for (int k = 1, i = 1, j = 1; k <= la; k++)
		{
			while (i <= lc && c[i] <= a[k])
			{
				i++;
			}
			// i == n + 1 => every number <= a[k]
			while (j <= lc && c[j] < a[k] + d)
			{
				j++;
			}
			j--;
			// j == 0 => every number >= a[k] + d
			if (j >= i)
			{
				ans = ans + csum[j] - csum[i - 1] - 1ll * (j - i + 1) * sum[a[k]];
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}