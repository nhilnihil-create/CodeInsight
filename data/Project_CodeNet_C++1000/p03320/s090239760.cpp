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

i64 dsum(i64 k)
{
	i64 res = 0;

	while (k > 0)
	{
		res += k % 10;
		k /= 10;
	}

	return res;
}

i64 f(i64 now)
{
	i64 ans = now;
	i64 d = 10;

	while (now > 0)
	{
		now /= 10;
		i64 cand = now * d + (d - 1);

		if (cand * dsum(ans) < ans * dsum(cand))
			ans = cand;

		d *= 10;
	}

	return ans;
}

int main()
{
	int k;
	scanf("%d", &k);

	i64 now = 1;

	for (int i = 0; i < k; i++)
	{
		printf("%lld\n", now);
		now = f(now + 1);
	}

	return 0;
}