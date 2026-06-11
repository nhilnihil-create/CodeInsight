#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a; cin >> a;
	string str; cin >> str;
	int dp[a + 50][2] = {0};
	dp[0][0] = (str[0] != '.');
	dp[0][1] = (str[0] != '#');
	for(int i=1; i<a; i++)
	{
		dp[i][0] = dp[i - 1][0] + (str[i] != '.');
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (str[i] != '#');
	}
	cout << min(dp[a - 1][0], dp[a - 1][1]) << '\n';
	return 0;
}