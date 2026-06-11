#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 2 * N;

int n, m;
int h[N], e[M], ne[M], idx;
int d[N];

void add(int a, int b)
{
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void dfs(int u, int v)
{
	d[u] = v;
	for (int i = h[u]; ~i; i = ne[i])
	{
		int j = e[i];
		if (d[j]) continue;
		
		dfs(j, v);
	}
}

int main()
{
	memset(h, -1, sizeof h);
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i ++ )
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b), add(b, a);
	}
	
	for (int i = 1, j = 1; i <= n; i ++ )
		if (!d[i])
		{
			dfs(i, j);
			j ++ ;
		}
			
	int res = 0;
	for (int i = 1; i <= n; i ++ ) res = max(res, d[i]);
	printf("%d\n", res);
    return 0;
}