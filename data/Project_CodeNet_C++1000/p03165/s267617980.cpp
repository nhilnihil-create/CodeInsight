#include <bits/stdc++.h>
#define endl "\n"
using namespace std;


int dp[3005][3005];



int32_t main()
{
	string a, b, ans;


	cin >> a >> b;



	int N = a.length();

	int M = b.length();




	for (int i = 0; i <= N; ++i)
		dp[i][0] = 0;


	for (int i = 0; i <= M; ++i)
		dp[0][i] = 0;


	dp[0][0] = 0;



	for (int i = 1; i <= N; ++i)
	{

		for (int j = 1; j <= M; ++j)
		{

			if (a[i - 1] == b[j - 1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);

		}

	}


	// for (int i = 0; i <= N; ++i)
	// {

	// 	for (int j = 0; j <= M; ++j)
	// 		cout << dp[i][j] << " ";

	// 	cout << endl;

	// }


	int i = N, j = M;


	while (i > 0 && j > 0)
	{

		if (a[i - 1] == b[j - 1])
		{

			ans.push_back(a[i - 1]);

			i--;
			j--;

		}
		else
		{

			if (dp[i - 1][j] > dp[i][j - 1])
				i--;
			else
				j--;

		}

	}


	reverse(ans.begin(), ans.end());



	//int ans = dp[N][M];

	cout << ans << endl;


}