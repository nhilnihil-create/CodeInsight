#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 510, M = 35;

int n, m;
int g[N][N], f[M][M];
int c[3][M];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= m; i ++ )
		for (int j = 1; j <= m; j ++ )
			cin >> f[i][j];
	for (int i = 1; i <= n; i ++ )
		for (int j = 1; j <= n; j ++ )
		{
			cin >> g[i][j];
			c[(i + j) % 3][g[i][j]] ++ ;
		}
	
	int res = 0x3f3f3f3f;
	for (int i = 1; i <= m; i ++ )
		for (int j = 1; j <= m; j ++ )
			for (int k = 1; k <= m; k ++ )
				if (i == j || i == k || j == k) continue;
				else
				{
					int sum = 0;
					for (int v = 1; v <= m; v ++ )
					{
						sum += c[0][v] * f[v][i];
						sum += c[1][v] * f[v][j];
						sum += c[2][v] * f[v][k];
					}
					res = min(res, sum);
				}
	cout << res << endl;
    return 0;
}