#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 510, M = 1010;

int n, m;
int g[N][N], cnt;
vector<PII> from, to;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= m; j ++ )
			cin >> g[i][j];
	
	for (int i = 1; i < n; i ++ )
		for (int j = 1; j <= m; j ++ )
			if (g[i][j] & 1)
			{
				g[i][j] -- ;
				g[i + 1][j] ++ ;
				from.push_back({i, j});
				to.push_back({i + 1, j});
				cnt ++ ;
			}
	
	for (int i = 1; i < m; i ++ )
		if (g[n][i] & 1)
		{
			g[n][i] -- ;
			g[n][i + 1] ++ ;
			from.push_back({n, i});
			to.push_back({n, i + 1});
			cnt ++ ;
		}
		
	// for (int i = 1; i <= n; i ++ )
	// {
		// for (int j = 1; j <= m; j ++ )
			// cout << g[i][j] << ' ';
		// puts("");
	// }
	
	cout << cnt << endl;
	for (int i = 0; i < cnt; i ++ )
		cout << from[i].F << ' ' << from[i].S << ' ' << to[i].F << ' ' << to[i].S << endl;
	return 0;
}