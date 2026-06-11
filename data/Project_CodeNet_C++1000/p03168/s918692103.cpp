#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
double p[3000], dp[3000][3000];
int main()
{
	int n, m, i, j, k; cin >> n;
	//double p[n + 1];
	for (i = 0; i < n; i++) cin >> p[i];
	//double dp[n + 1][n + 1];
	dp[0][0] = (1 - p[0]);
	dp[0][1] = p[0];
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < 3000; j++)
		{
			//head
			if (j > 0)
				dp[i][j] += p[i] * dp[i - 1][j - 1];
			//tail
			dp[i][j] += (1 - p[i]) * dp[i - 1][j];
			//cout << dp[i][j] << " ";
		}
		//cout << endl;
	}
	double ans = 0;
	for (i = n / 2 + 1; i < 3000; i++) ans += dp[n - 1][i];

	cout << setprecision(10) << fixed;
	cout << ans << endl;




}
