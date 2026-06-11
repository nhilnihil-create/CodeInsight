#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int m = 1e9+7;
int main()
{
ll h,w;
cin>>h>>w;
char a[h][w];
for(int i =0;i<h;i++)
{
	for(int j =0;j<w;j++)
	{
		cin>>a[i][j];
	}
}
int dp[h][w];
for(int i =0;i<h;i++)
{
	for(int j =0;j<w;j++) dp[i][j]=0;
}
if(a[0][0]=='#') dp[0][0]=0;
else dp[0][0]=1;
for(int j=1;j<w;j++)
{
	if(a[0][j]=='#') dp[0][j]=0;
	else dp[0][j]=dp[0][j-1];
}

for(int i=1;i<h;i++)
{
	if(a[i][0]=='#') dp[i][0]=0;
	else dp[i][0]=dp[i-1][0];
}
for(int i =1;i<h;i++)
{
	for(int j =1;j<w;j++)
	{
		if(a[i][j]=='#') dp[i][j]=0;
		else {
			if(a[i-1][j]=='.')
			{
				dp[i][j]+=dp[i-1][j];
			}
			if(a[i][j-1]=='.')
			{
				dp[i][j]+=dp[i][j-1];
			}
			if(a[i-1][j]=='#' && a[i][j-1]=='#') dp[i][j]=0;
			
			dp[i][j]%=m;
		}
	}
}
	cout<<dp[h-1][w-1]<<"\n";   	
}