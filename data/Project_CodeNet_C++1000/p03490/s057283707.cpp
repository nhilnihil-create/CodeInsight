#include <bits/stdc++.h>
using namespace std;
 
int dp[8005][16005];
int a[8001];
string s;
int x,y;
int k,w;
int main()
{
	getline(cin,s);
	cin>>x>>y;
	for(int i=0;i<=s.size()-1;i++)
	{
		if(s[i]=='T')
		{
			k++;
			a[k]=w;
			w=0;
		}
		else
			w++;
	}
	k++;
	a[k]=w;
	
	dp[1][a[1]+8000]=1;
	for(int i=3;i<=k;i+=2)
		for(int j=0;j<=16000;j++)
		{
			if(j+a[i]<=16000)
				dp[i][j]=dp[i-2][j+a[i]];
			if(j-a[i]>=0)
				dp[i][j]=dp[i][j]||dp[i-2][j-a[i]];
		}
	
	dp[0][8000]=1;
	for(int i=2;i<=k;i+=2)
		for(int j=0;j<=16000;j++)
		{
			if(j+a[i]<=16000)
				dp[i][j]=dp[i-2][j+a[i]];
			if(j-a[i]>=0)
				dp[i][j]=dp[i][j]||dp[i-2][j-a[i]];
		}
	int ans=0;
	if(k%2==1)
		ans=dp[k][x+8000]&&dp[k-1][y+8000];
	else
		ans=dp[k][y+8000]&&dp[k-1][x+8000];
	
	if(ans==0) cout<<"No";
	else cout<<"Yes";
	return 0;
}