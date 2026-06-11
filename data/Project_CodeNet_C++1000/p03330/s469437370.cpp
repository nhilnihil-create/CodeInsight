#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 510, M = 35, INF = 0x3f3f3f3f;

int n, m;
int c[M][M];
int cnt[3][M];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i ++ )
		for (int j = 1; j <= m; j ++ )
			cin >> c[i][j];
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
		{
			int x;
			cin >> x;
			cnt[(i + j) % 3][x] ++ ;
		}
	
	LL res = 1e18;
	for (int i = 1; i <= m; i ++ )
		for (int j = 1; j <= m; j ++ )
			for(int k = 1; k <= m; k ++ )
				if (i != j && j != k && k != i)
				{
					LL t = 0;
					for (int u = 1; u <= m; u ++ )
					{
						t += (LL)cnt[0][u] * c[u][i];
						t += (LL)cnt[1][u] * c[u][j];
						t += (LL)cnt[2][u] * c[u][k];
					}
					res = min(res, t);
				}
	
	cout << res << endl;
	return 0;
}