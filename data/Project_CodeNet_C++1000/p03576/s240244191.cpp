#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 55, M = 110;

int n, m;
int x[N], y[N], xx[N], yy[N];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++ )
	{
		scanf("%d%d", &x[i], &y[i]);
		xx[i] = x[i], yy[i] = y[i];
	}
	sort(xx, xx + n), sort(yy, yy + n);
	
	LL res = 4e18;
	for (int i = 0; i < n; i ++ )
		for (int j = 0; j <= i; j ++ )
			for (int k = 0; k < n; k ++ )
				for (int l = 0; l <= k; l ++ )
				{
					int cnt = 0;
					for (int u = 0; u < n; u ++ )
						if (x[u] <= xx[i] && x[u] >= xx[j] && y[u] <= yy[k] && y[u] >= yy[l])
							cnt ++ ;
					if (cnt >= m) res = min(res, (LL)(xx[i] - xx[j]) * (yy[k] - yy[l]));
				}
	cout << res << endl;
	return 0;
}