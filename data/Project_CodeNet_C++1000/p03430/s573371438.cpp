#include<iostream>
#include<string>
using namespace std;
int dp[301][301][301];
int main()
{
	string str;
	int q;
	cin>>str>>q;
	int l=str.size();
//	cout<<l<<endl;
	for(int i=l-1;i>=0;i--)
	{
		for(int k=0;k<=q;k++)
			dp[i][i][k]=1;
	}
	for(int i=l-1;i>=0;i--)
	{
		
		for(int j=i+1;j<=l-1;j++)
		{
			for(int k=0;k<=q;k++)
			{
				//dp[i][i][k]=1; 
				if(str[i]==str[j]) dp[i][j][k]=max(dp[i+1][j-1][k]+2,dp[i][j][k]);
				else
				{
					
					if(k!=0)
					{
						dp[i][j][k]=max(dp[i+1][j-1][k-1]+2,dp[i][j][k]);
					}
					dp[i][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
					dp[i][j][k]=max(dp[i][j-1][k],dp[i][j][k]);
				}
			}
		}
	}
	int ans=0;
	for(int k=0;k<=q;k++)
			ans=max(ans,dp[0][l-1][k]);
	cout<<ans<<endl;
 } 