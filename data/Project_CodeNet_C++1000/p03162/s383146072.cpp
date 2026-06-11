#include <bits/stdc++.h>
using namespace std;

typedef struct {
int first;
int second;
int third;
}triple;

int main()
{
	int n;
	cin >>n;
	triple happ[n];

	for (int i=0;i<n;i++)	cin >> happ[i].first >>happ[i].second >> happ[i].third ;
	
	int dp[n][3];

	memset(dp,0,sizeof(dp));
	dp[0][0]=happ[0].first;
	dp[0][1]=happ[0].second;
	dp[0][2]=happ[0].third;

	for (int i=1;i<n;i++)
	{	
		dp[i][0]=max(dp[i-1][1],dp[i-1][2])+happ[i].first;
		dp[i][1]=max(dp[i-1][0],dp[i-1][2])+happ[i].second;
		dp[i][2]=max(dp[i-1][0],dp[i-1][1])+happ[i].third;
	}
	cout << max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
	return 0;
}