#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
long long n,dp[6][5];
char s[20],*k="MARCH";
int main()
{
	cin >> n;
	long long cnt[5]={0};
	for(int i=0; i<n; i++)
	{
		cin >> s;
		char *v=strchr(k,s[0]);
		if(v) cnt[v-k]++;
	}
	for(int i=0; i<=5; i++) dp[i][0]=1;
	for(int i=1; i<=5; i++)
		for(int j=1; j<=3; j++)
			if(i>=j)
			{
				dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*cnt[i-1];
				//cout << dp[i][j]<< ' ';
			}
	cout << dp[5][3];
	return 0;
}
