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

	vector<int> arr(n);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	sort(arr.begin(), arr.end());

	int ni = arr.back();
	int ki = arr[0];
	int nowd = arr.back();

	for (int i = 0; i < n - 1; i++)
	{
		int dx = abs((ni + 1) / 2 - arr[i]);

		if (ni % 2 == 0)
			dx = min(dx, abs(ni / 2 + 1 - arr[i]));
		
		if (dx < nowd)
		{
			nowd = dx;
			ki = arr[i];
		}
	}

	printf("%d %d\n", ni, ki);

	return 0;
}