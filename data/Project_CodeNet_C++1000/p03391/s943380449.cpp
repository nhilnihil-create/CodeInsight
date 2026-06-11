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

	int minb = 1987654321;
	i64 dfsum = 0;
	i64 bs = 0;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		bs += b;

		if (b > a)
			dfsum += b - a;
		
		if (a > b)
			minb = min(minb, b);
	}

	if (dfsum == 0)
	{
		printf("0\n");
		return 0;
	}

	printf("%lld\n", bs - minb);

	return 0;
}