#include <bits/stdc++.h>
#define M 1000000007
#define ll long long
#define endl "\n"
using namespace std;

int n, m;

ll dp[1001][1001];

char mat[1001][1001];


ll countWays(int x, int y)
{

	if (mat[x][y] == '#')
		return 0;

	if (x == n - 1 && y == m - 1)
		return 1;

	if (x < 0 || x >= n || y < 0 || y >= m)
		return 0;


	if (dp[x][y] != -1)
		return dp[x][y];


	return dp[x][y] = (countWays(x, y + 1) % M + countWays(x + 1, y) % M) % M;


}





int32_t main()
{


	cin >> n >> m;


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> mat[i][j];
	}



	memset(dp, -1, sizeof(dp));



	cout << countWays(0, 0) % M << endl;



}