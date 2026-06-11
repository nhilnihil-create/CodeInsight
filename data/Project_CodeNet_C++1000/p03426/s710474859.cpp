#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 310, M = 1010;

int n, m, d, k;
int g[N][N];
PII p[N * N];
vector<vector<LL>> h;

int main()
{
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
		{
			int x;
			scanf("%d", &x);
			g[i][j] = x;
			p[x] = {i, j};
		}
	p[0] = p[d];
	
	h.resize(d + 10);
	for (int i = 0; i < d; i ++ )
	{
		h[i].resize((n * m + d - 1) / d + 10);
		h[i][0] = 0;
		for (int j = 0; i + (j + 1) * d <= n * m; j ++ )
		{
			PII st = p[i + j * d], ed = p[i + (j + 1) * d];
			LL sum = abs(st.F - ed.F) + abs(st.S - ed.S);
			h[i][j + 1] = h[i][j] + sum;
		}
	}
	
	scanf("%d", &k);
	while (k -- )
	{
		int l, r;
		scanf("%d%d", &l, &r);
		if (l == r) puts("0");
		else
		{
			int t = l % d;
			l /= d, r /= d;
			printf("%lld\n", h[t][r] - h[t][l]);
		}
	}
	return 0;
}