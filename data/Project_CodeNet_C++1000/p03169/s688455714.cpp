#include <bits/stdc++.h>
using namespace std;

int n;
int a[4];

double dp[301][301][301];

double dp_count(int a1, int a2, int a3)
{
	if(a1 < 0 || a2 < 0 || a3 < 0)
		return 0;
	
	if(dp[a1][a2][a3] == -1)
	{
		double res = 0;
		
		res = n + a1 * dp_count(a1 - 1, a2, a3) + a2 * dp_count(a1 + 1, a2 - 1, a3) + a3 * dp_count(a1, a2 + 1, a3 - 1);
		
		dp[a1][a2][a3] = res / double(a1 + a2 + a3);
	}
	
	return dp[a1][a2][a3];
}

int main()
{
	for(int i = 0; i <= 300; i++)
	for(int i1 = 0; i1 <= 300; i1++)
	for(int i2 = 0; i2 <= 300; i2++)
	dp[i][i1][i2] = -1;
	dp[0][0][0] = 0;
	
	cin >> n;
	
	for(int i = 1; i <= n; i++)
	{
		int b;
		cin >> b;
		a[b]++;
	}
	
	cout << setprecision(12) << dp_count(a[1], a[2], a[3]);
	
	return 0;
}