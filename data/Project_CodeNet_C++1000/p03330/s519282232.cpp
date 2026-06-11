#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 1010, M = 35;

int n, m;
int f[M][M];
int c[3][M];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i ++ )
		for (int j = 1; j <= m; j ++ )
			cin >> f[i][j];
	
	for (int i = 0; i < n; i ++ )
		for (int j = 0; j < n; j ++ )
		{
			int t;
			cin >> t;
			c[(i + j) % 3][t] ++ ;
		}
		
	LL res = 1e18;
	for (int i = 1; i <= m; i ++ )
		for (int j = 1; j <= m; j ++ )
			for (int k = 1; k <= m; k ++ )
			{
				if (i == j || j == k || i == k) continue;
				
				LL sum = 0;
				for (int v = 1; v <= m; v ++ )
				{
					sum += f[v][i] * c[0][v];
					sum += f[v][j] * c[1][v];
					sum += f[v][k] * c[2][v];
				}
				res = min(res, sum);
			}
	
	cout << res << endl;
	return 0;
}