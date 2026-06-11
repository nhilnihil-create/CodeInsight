#include "bits/stdc++.h"
using namespace std;

#define ll long long
const ll hell = 1e9+7;
string s[1005];
ll dp[1005][1005];

int main()
{
	ll h,w;
	cin>>h>>w;
	dp[0][0]=1;
	
	for(int i=0;i<h;i++)
	{
		cin>>s[i];
		for(int j=0;j<w;j++)
		{
			if(s[i][j]=='#')
			{
				dp[i][j]=0;
				continue;
			}
			
			if(j>0) dp[i][j] += dp[i][j-1];
			dp[i][j]%=hell;
			if(i>0) dp[i][j] += dp[i-1][j];	
			dp[i][j]%=hell;		
			
		}
		
	}
	
	cout<<dp[h-1][w-1]%hell<<endl;
}
