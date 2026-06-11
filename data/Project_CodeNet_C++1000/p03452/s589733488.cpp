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

vector<ii> edge[100005];
i64 pos[100005];
bool visit[100005];

bool dfs(int v)
{
	for (auto& e : edge[v])
	{
		if (visit[e.first])
		{
			if (pos[e.first] != pos[v] + e.second)
				return false;

			continue;
		}

		visit[e.first] = true;
		pos[e.first] = pos[v] + e.second;

		if (!dfs(e.first))
			return false;
	}

	return true;
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
	{
		int l, r, d;
		scanf("%d %d %d", &l, &r, &d);

		edge[l].emplace_back(r, -d);
		edge[r].emplace_back(l, d);
	}

	for (int i = 1; i <= n; i++)
	{
		if (visit[i])
			continue;

		visit[i] = true;

		if (!dfs(i))
		{
			printf("No\n");
			return 0;
		}
	}

	printf("Yes\n");

	return 0;
}