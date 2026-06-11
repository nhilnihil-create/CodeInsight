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
#define all(x) (x).begin(), (x).end()
#define xx first
#define yy second

using namespace std;

using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;

int main()
{
	int n;
	scanf("%d", &n);

	i64 asum = 0;
	i64 dfsum = 0;

	vector<int> a(n), b(n);
	int bsmall = 0;	
	int minb = 1987654321;

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &a[i], &b[i]);

		if (a[i] <= b[i])
			asum += a[i];

		if (b[i] > a[i])
			dfsum += b[i] - a[i];
		
		if (a[i] > b[i])
		{
			bsmall++;
			minb = min(minb, b[i]);
		}
	}

	if (dfsum == 0)
	{
		printf("0\n");
		return 0;
	}

	// b[i] < a[i]인게 1개 뿐이면 그대로 끝
	if (bsmall == 1)
	{
		printf("%lld\n", asum + dfsum);
		return 0;
	}

	// bsmall이 2개 이상이면, a 입장에서는 하나씩 깎아나가면서 다 0으로 만드는게 이득
	// b < a 인 b중에 제일 작은거 하나 빼고 나머지 전체 합만큼 가능

	i64 bs = -minb;

	for (int i = 0; i < n; i++)
		bs += b[i];
	
	printf("%lld\n", bs);

	return 0;
}