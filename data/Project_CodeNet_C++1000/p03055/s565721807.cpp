#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <cstring>

using namespace std;

struct Edge {
	int to, next;
}es[400010];
int first[200010], te = 0;

void addE(int a, int b)
{
	te++;
	es[te].to = b;
	es[te].next = first[a];
	first[a] = te;
}

int n;
int d[200010];
queue<int> Q;

void bfs(int pos)
{
	Q.push(pos);
	memset(d, -1, sizeof d);
	d[pos] = 0;
	while (!Q.empty())
	{
		int p = Q.front();
		Q.pop();
		for (int e = first[p]; e; e = es[e].next)
		{
			int to = es[e].to;
			if (d[to] != -1) continue;
			d[to] = d[p] + 1;
			Q.push(to);
		}
	}
}

int getdist()
{
	bfs(1);
	int pos = 1;
	for (int i = 2; i <= n; i++)
		if (d[i] > d[pos])
			pos = i;
	bfs(pos);
	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret = max(ret, d[i]);
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		addE(a, b), addE(b, a); 
	}
	if (getdist() % 3 == 1)
		cout << "Second" << endl;
	else
		cout << "First" << endl;
	return 0;
}
