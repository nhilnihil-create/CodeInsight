#include <bits/stdc++.h>
#pragma warning (disable : 4996)
using namespace std;
const int INF = -1234567890;
typedef pair<int, int> pii;
int main()
{
	int a[100006];
	int n, m; scanf("%d %d", &n, &m);
	fill(a, a + n + 3, INF);
	vector<pii> graph[100006];
	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		graph[x].push_back({ y,z });
		graph[y].push_back({ x,-z });
	}
	for (int i = 1; i <= n; i++)
	{
		if (a[i] != INF) continue;
		a[i] = 0;
		queue<pii> v;
		v.push({ i,0 });
		while (!v.empty())
		{
			int tpx = v.front().first;
			int tpy = v.front().second;
			v.pop();
			for (int i = 0; i < graph[tpx].size(); i++)
			{
				auto loc = graph[tpx][i];
				if (a[loc.first] != INF)
				{
					if (a[loc.first] - tpy != loc.second) return !printf("No");
				}
				else
				{
					a[loc.first] = loc.second + tpy;
					v.push({ loc.first,a[loc.first] });
				}
			}
		}
	}
	return !printf("Yes");
}