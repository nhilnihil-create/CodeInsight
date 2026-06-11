#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 510, M = 35, INF = 0x3f3f3f3f;

int n, m;
int c[M][M], g[N][N];
vector<LL> sum;
vector<pair<LL, int> > a[3];

void get(int u)
{
	for (int t = 1; t <= m; t ++ )
	{
		LL sum = 0;
		for (int i = 1; i <= n; i ++ )
			for (int j = 1; j <= n; j ++ )
				if ((i + j) % 3 == u)
				{
					int p = g[i][j];
					sum += c[p][t];
				}
		a[u].push_back({sum, t});
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i ++ )
		for (int j = 1; j <= m; j ++ )
			cin >> c[i][j];
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
			cin >> g[i][j];
			
	for (int i = 0; i < 3; i ++ )
	{
		get(i);
		sort(a[i].begin(), a[i].end());
	}
	
	for (int i = 0; i < 3; i ++ )
		for (int j = 0; j < 3; j ++ )
			for (int k = 0; k < 3; k ++ )
				if (a[0][i].S != a[1][j].S && a[1][j].S != a[2][k].S && a[0][i].S != a[2][k].S)
					sum.push_back(a[0][i].F + a[1][j].F + a[2][k].F);
				
	LL res = INF;
	for (auto u : sum) res = min(res, u);
	cout << res << endl;
	return 0;
}