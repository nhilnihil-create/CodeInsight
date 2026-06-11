#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>
#include <bitset>
#include <map>
#include <set>
#include <tuple>
#include <string.h>
#include <math.h>
#include <random>
#include <functional>
#include <assert.h>
#include <math.h>

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{
	int n;
	scanf("%d", &n);

	vector<int> arr(n + 1);

	for (int i = 1; i <= n; i++)
		scanf("%d", &arr[i]);

	vector<i64> sum(n + 1);

	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + arr[i];

	int lc = 1;
	int rc = 3;

	i64 ans = sum[n];

	for (int cut = 2; cut <= n - 2; cut++)
	{
		//1 ~ cut / cut + 1 ~ n 양쪽으로 분할해서 생각
		// 각 양쪽 구간에서 최대한 min max 차이를 줄인다.
		i64 lsum = sum[cut];
		i64 rsum = sum[n] - lsum;

		while (lc < cut - 1)
		{
			i64 nowg = llabs(lsum - 2 * sum[lc]);
			i64 nextg = llabs(lsum - 2 * sum[lc + 1]);

			if (nowg <= nextg)
				break;

			lc++;
		}

		while (rc < n - 1)
		{
			i64 nows = sum[rc] - lsum;
			i64 nexts = sum[rc + 1] - lsum;

			i64 nowg = llabs(rsum - 2 * nows);
			i64 nextg = llabs(rsum - 2 * nexts);

			if (nowg <= nextg)
				break;

			rc++;
		}

		i64 p = sum[lc];
		i64 q = sum[cut] - p;
		i64 r = sum[rc] - sum[cut];
		i64 s = sum[n] - sum[rc];

		ans = min(ans, max({ p,q,r,s }) - min({ p,q,r,s }));
	}

	printf("%lld\n", ans);

	return 0;
}