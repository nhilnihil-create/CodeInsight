#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010, M = 3, INF = 0x3f3f3f3f;

int n, m;
LL w[N][M];
LL val[N];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++ )
		for (int j = 0; j < M; j ++ )
			scanf("%lld", &w[i][j]);
	
	LL res = -1e18;
	for (int t = 0; t < 1 << M; t ++ )
	{
		for (int i = 0; i < n; i ++ )
		{
			val[i] = 0;
			for (int j = 0; j < M; j ++ )
			{
				if ((t >> j) & 1) val[i] += w[i][j];
				else val[i] -= w[i][j];
			}
		}
		sort(val, val + n);
		reverse(val, val + n);
		
		LL s = 0;
		for (int i = 0; i < m; i ++ ) s += val[i];
		res = max(res, s);
	}
	printf("%lld\n", res);
	return 0;
}