#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

int N, d;
int V[2][50];
int E[2][50][50];

struct Node
{
	int n;
	int mt;
	int h;
	bool sel[50];
	bool operator< (const Node & node) const
	{
		return h < node.h;
	}
	Node() : n(0), mt(0x0FFFFFFF), h(0)
	{
	}
	Node(const Node & node) : n(node.n), mt(node.mt), h(node.h)
	{
		if(n > 0)
			memcpy(sel, &node.sel, sizeof(bool) * n);
	}
};

int tdiff(int t1, int t2)
{
	int diff = abs(t1 - t2);
	return min(diff, 24 - diff);
}

int bnb(int minedge)
{
	priority_queue <Node> pq;
	pq.push(Node());
	int bnd = 0;
	while (!pq.empty())
	{
		Node node = pq.top();
		pq.pop();
		if (node.h < bnd)
			continue;
		if (node.n == N)
		{
			bnd = max(bnd, node.mt);
			if (minedge <= bnd)
				break;
			continue;
		}
		for (int s = 0; s < 2; ++s)
		{
			node.sel[node.n] = s;

			// compute new minimum tdiff
			// between new vertex and others.
			int backup = node.mt;
			for (int m = 0; m < node.n; ++m)
				node.mt = min(node.mt, tdiff(V[node.sel[m]][m], V[s][node.n]));
			
			// compute heuristic
			// select others having always best edges
			node.h = node.mt;
			for (int m = node.n + 1; m < N; ++m)
				node.h = min(node.h, E[1][node.n][m]);

			++node.n;
			pq.push(node);
			node.mt = backup;
			--node.n;
		}
	}
	return min(bnd, minedge);
}

int main(void)
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &N);
	int minedge = 0x0FFFFFFF;
	int dupchk[13] = { 0, };
	for (int n = 0; n < N; ++n)
	{
		scanf("%d", &d);
		++dupchk[d];
		V[0][n] = min(d, 24 - d);
		V[1][n] = max(d, 24 - d);
		minedge = min(minedge, V[0][n]);
	}

	// pigeon's hole
	if (dupchk[0] >= 1)
	{
		printf("0");
		return 0;
	}
	for (int h = 1; h < 12; ++h)
		if (dupchk[h] >= 3)
		{
			printf("0");
			return 0;
		}
	if (dupchk[12] >= 2)
	{
		printf("0");
		return 0;
	}

	for (int n = 0; n < N; ++n)
		for (int m = n + 1; m < N; ++m)
		{
			E[0][n][m] = 0x0FFFFFFF;
			E[1][n][m] = 0;
			for (int i = 0; i < 2; ++i)
				for (int j = 0; j < 2; ++j)
				{
					int td = tdiff(V[i][n], V[j][m]);
					E[0][n][m] = min(E[0][n][m], td);
					E[1][n][m] = max(E[1][n][m], td);
				}
		}
	printf("%d", bnb(minedge));
	return 0;
}