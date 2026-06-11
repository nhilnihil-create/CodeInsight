#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

int a[N];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

	LL suma = 0,  sumb = 0;
	LL ans = 0;
	for (int j = 1, i = 1; j <= n; j++)  //先枚举右端点, 右端点往前跑
	{
		suma ^= a[j], sumb += a[j];
		
		while (i <= j && suma != sumb)
		{
			suma ^= a[i], sumb -= a[i];
			i++;
		}
		
		ans += j - i + 1;
	}

	printf("%lld\n", ans);

	return 0;
}
