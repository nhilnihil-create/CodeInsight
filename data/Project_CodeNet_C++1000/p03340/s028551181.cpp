#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10;

int n;
LL a[N];
LL res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);

	LL sum1 = 0, sum2 = 0;
	for (int i = 1, j = 1; i <= n; i++)
	{
		while (j <= n + 1 && sum1 == sum2) //j可以枚举到n
		{
			//printf("sum1 sum2: %lld %lld\n", sum1, sum2);
			sum1 ^= a[j]; sum2 += a[j];
			j++;
		}

		//printf("sum1 sum2: %lld %lld\n", sum1, sum2);
		//printf("---%d %d\n", i, j);
		
		//[i, i...j - 2]之间都是合法的
		res += (j - 2) - i + 1;

		sum1 ^= a[j - 1]; sum2 -= a[j - 1];
		j--; //最后一个不合法的退掉

		sum1 ^= a[i]; sum2 -= a[i];
	}

	printf("%lld\n", res);

	return 0;
}

