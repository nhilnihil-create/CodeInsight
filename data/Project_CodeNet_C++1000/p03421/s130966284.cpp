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
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);

	for (int r = 0; r <= a - 1 && n - r >= b; r++)
	{
		//맨앞에 r개 짜투리를 남겨놓고
		//나머지를 b개 단위로 묶은 그냥 숫자로 본다
		if ((n - r + b - 1) / b != a - r)
			continue;

		for (int i = 1; i <= r; i++)
			printf("%d ", i);

		//r+1부터 역순 짜투리
		for (int k = 0; k < a - r; k++)
		{
			int start = min(n, r + (k + 1) * b);

			while (start > r + k * b)
			{
				printf("%d ", start);
				start--;
			}
		}

		return 0;
	}

	printf("-1\n");

	return 0;
}