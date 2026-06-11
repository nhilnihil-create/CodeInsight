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

	LL suma = 0, sumb = 0;
	LL ans = 0;

	for (int i = 1, j = 1; i <= n; i++)  //枚举左端点
	{
		while (j - 1 <= n && suma == sumb) //滑动右窗口
		{
			suma ^= a[j], sumb += a[j];
			j++;
		}

		ans += j - 1 - i;

		suma ^= a[j - 1], sumb -= a[j - 1];	
		suma ^= a[i], sumb -= a[i];	
		j--;
	}

	printf("%lld\n", ans);

	return 0;
}

