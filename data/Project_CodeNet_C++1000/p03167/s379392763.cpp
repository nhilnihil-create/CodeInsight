#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const ll mod = (ll) 1e9 +7;

ll dp[1005][1005];
char s[1005][1005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int w,h;
	cin>>w>>h;
	
	for(int i=0;i<w;i++)
	for(int j=0;j<h;j++)
	cin>>s[i][j];
	
	dp[0][1] = 1;
	
	for(int i=1;i<=w;i++)
	{
		for(int j=1;j<=h;j++)
		{
			if(s[i-1][j-1]=='.')
			dp[i][j] = (dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
			
			else
			dp[i][j] = 0;
		}
	}
	
	cout<<dp[w][h]<<"\n";
	return 0;
}