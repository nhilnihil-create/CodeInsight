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
	int l;
	scanf("%d", &l);
	l--;

	int nowlen = 1;

	vector<ii> edge;
	vector<int> len;

	for (int i = 19; i > 1; i--)
	{
		edge.emplace_back(i, i + 1);
		len.push_back(nowlen);

		edge.emplace_back(i, i + 1);
		len.push_back(0);

		nowlen *= 2;
	}

	// 1 to 2 edge를 0이 나오는 위치들 기준으로 구분
	edge.emplace_back(1, 20);
	len.push_back(l);
	for (int b = 0; b <= 18; b++)
	{
		int k = l;
		if ((k & (1 << b)) == 0)
			continue;

		k -= k % (1 << b);
		k -= 1 << b;

		edge.emplace_back(1, 20 - b);
		len.push_back(k);

		if (k == 0)
			break;
	}

	if (l > 524288)
	{
		edge.emplace_back(1, 2);
		len.push_back(0);
		edge.emplace_back(1, 2);
		len.push_back(262144);
	}

	printf("20 %d\n", edge.size());

	for (int i = 0; i < edge.size(); i++)
		printf("%d %d %d\n", edge[i].xx, edge[i].yy, len[i]);

	return 0;
}