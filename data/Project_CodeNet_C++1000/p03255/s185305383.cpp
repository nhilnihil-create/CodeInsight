/*input
10 8851025
38 87 668 3175 22601 65499 90236 790604 4290609 4894746

5 1
1 999999997 999999998 999999999 1000000000

16 10
1 7 12 27 52 75 731 13856 395504 534840 1276551 2356789 9384806 19108104 82684732 535447408

2 100
1 10
*/
#include <bits/stdc++.h>
using namespace std;
const int MXN = 200010;
const long long INF = 1e18;
int n;
long long ans, m, a[MXN];

int main()
{
	scanf("%d %lld", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), a[i] = a[i-1] + a[i];
	ans = INF;
	for (int i = 1; i <= n; i++)
	{
		long long s = m * (i + n);
		for (int j = n, x = 1; j >= 1 && s < ans; j -= i, x++)
		{
			int k = max(j - i + 1, 1);
			if (j == n) s += 2 * (a[j] - a[k - 1]);
			s += (2 * x + 1) * (a[j] - a[k-1]);
		}
		ans = min(ans, s);
	}
	printf("%lld\n", ans);
	return 0;
}
