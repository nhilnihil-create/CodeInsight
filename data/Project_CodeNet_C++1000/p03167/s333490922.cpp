#include <bits/stdc++.h>
#define M 1000000007
#define ll long long
#define endl "\n"
using namespace std;

int n, m;

ll dp[1001][1001];

char mat[1001][1001];



int32_t main()
{


	cin >> n >> m;


	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
			cin >> mat[i][j];
	}



	memset(dp, 0, sizeof(dp));



	for (int i = 0; i < n; ++i) {

		if (mat[0][i] == '#')
			break;

		dp[0][i] = 1;
	}



	for (int i = 0; i < m; ++i) {

		if (mat[i][0] == '#')
			break;

		dp[i][0] = 1;
	}


	dp[0][0] = 1;


	for (int i = 1; i < n; ++i)
	{

		for (int j = 1; j < m; ++j)
		{
			if (mat[i][j] == '.')
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % M;
		}

	}




	cout << dp[n - 1][m - 1] % M << endl;


}