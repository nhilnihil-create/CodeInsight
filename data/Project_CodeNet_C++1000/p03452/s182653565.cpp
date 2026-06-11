#include<stdio.h>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<math.h>
#include<algorithm>
using namespace std;

#define INF 987654321
#define ll long long

ll Max, Min, gap;
int N, M;
vector<pair<pair<int, int>, int> > q;
vector<pair<int, int> > g[100101];
int parent[100101], dp[20][100101], p[100101], h[100101];
ll depth[100101];
vector<bool> visited(100101);

int Find(int n)
{
	if (n == parent[n]) return n;
	return parent[n] = Find(parent[n]);
}

void Union(int l, int r, int d)
{
	int pl = l, pr = r;
	l = Find(l); r = Find(r);
	if (l == r)
	{
		q.push_back({ {pl, pr}, d });
		return;
	}

	parent[l] = r;
	g[pl].push_back({ pr, d });
	g[pr].push_back({ pl, -d });
}

void DFS(int n, int prev)
{
	Max = max(Max, depth[n]);
	Min = min(Min, depth[n]);
	visited[n] = true;

	for (int i = 0; i < g[n].size(); i++)
	{
		int next = g[n][i].first, cost = g[n][i].second;
		if (next == prev) continue;

		p[next] = n;
		depth[next] = depth[n] + cost;
		h[next] = h[n] + 1;
		DFS(next, n);
	}
}

int LCA(int a, int b) //LCA를 잘못 구했다.
{
	if (h[a] != h[b])
	{
		if (h[a] < h[b]) swap(a, b);
		int diff = h[a] - h[b];
		for (int i = 0; diff; i++)
		{
			if (diff % 2) a = dp[i][a];
			diff /= 2;
		}
	}

	if (a == b) return a;

	for (int i = 19; i >= 0; i--)
		if (dp[i][a] != dp[i][b])
		{
			a = dp[i][a];
			b = dp[i][b];
		}
	return p[a];
}

int main()
{
	for (int i = 0; i < 100101; i++)
		parent[i] = i;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		Union(a, b, c);
	}

	//컴포넌트가 하나가 아닐 수도 있다.
	//항상 같은 컴포넌트의 정점끼리만 쿼리가 들어온다.
	for (int i = 1; i <= N; i++)
	{
		if (!visited[i])
		{
			Max = 0;
			Min = 0;

			depth[i] = 0;
			h[i] = 0;
			DFS(i, 0);

			gap = max(gap, Max - Min);
		}
	}

	//잊은 것 : [0, 10^9] 범위니까 트리의 최장 경로 검사가 필요
	//이 문제에서는 트리의 특수성 때문에 간단하게 검사할 수 있다.
	//컴포넌트가 여러 개면 컴포넌트끼리 따로 처리해 줘야 한다.
	if (gap > 1'000'000'000LL)
		return !printf("No");

	for (int i = 1; i <= N; i++)
		dp[0][i] = p[i];

	for (int i = 1; i < 20; i++)
		for (int j = 1; j <= N; j++)
			dp[i][j] = dp[i - 1][dp[i - 1][j]];

	for (int i = 0; i < q.size(); i++)
	{
		int l = q[i].first.first, r = q[i].first.second, d = q[i].second;
		int lca = LCA(l, r);
		if (abs(depth[l] - depth[r]) != (ll)d)
			return !printf("No");
	}

	printf("Yes");
	return 0;
}