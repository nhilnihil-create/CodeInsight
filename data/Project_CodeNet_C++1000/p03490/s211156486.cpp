#include<bits/stdc++.h>
using namespace std;
bool dp[8001][16001];
int a[8001];
int main()
{
	ios::sync_with_stdio(false);
	string s;
	int x,y;
	cin>>s>>x>>y;
	int k=0,w=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='T')
		{
			a[++k]=w;
			w=0;
		}
		else w++;
	}
	a[++k]=w;
	dp[1][a[1]+8000]=true;
	for(int i=3;i<=k;i+=2)
	{
		for(int j=0;j<=16000;j++)
		{
			if(j+a[i]<=16000)
				dp[i][j]=dp[i-2][j+a[i]];
			if(j-a[i]>=0)
				dp[i][j]=dp[i][j]||dp[i-2][j-a[i]];
		}
	}
	dp[0][8000]=true;
	for(int i=2;i<=k;i+=2)
	{
		for(int j=0;j<=16000;j++)
		{
			if(j+a[i]<=16000)
				dp[i][j]=dp[i-2][j+a[i]];
			if(j-a[i]>=0)
				dp[i][j]=dp[i][j]||dp[i-2][j-a[i]];
		}
	}
	bool ans;
	if(k%2==0)
		cout<<(dp[k][y+8000]&&dp[k-1][x+8000]?"Yes\n":"No\n");
	else
		cout<<(dp[k][x+8000]&&dp[k-1][y+8000]?"Yes\n":"No\n");
	return 0;
}