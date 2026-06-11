#include<cstdio>
#include<cstring>
typedef long long ll;
int n, m;
char a[200200];
char b[200200];
int main()
{
	ll ans = 0;
	scanf("%s", &a[1]);
	n = strlen(&a[1]);
	for (int i = 1; i <= n; i++)
	{
		if (a[i] == 'A')
		{
			b[++m] = '(';
		}
		else if (a[i] == 'B' && i < n && a[i + 1] == 'C')
		{
			b[++m] = ')';
			i++;
		}
		else b[++m] = a[i];
	}
	ll open_count = 0;
	for (int i = 1; i <= m; i++)
	{
		if (b[i] == '(') open_count++;
		else if (b[i] == ')') ans += open_count;
		else open_count = 0;
	}
	printf("%lld\n", ans);
	return 0;
}
