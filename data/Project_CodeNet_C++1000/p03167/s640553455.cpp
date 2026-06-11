#include <iostream>
using namespace std;

int main() {
	int h,w,i,j;
	cin>>h>>w;
	char c[h][w];
	int dp[h][w]={0};
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		cin>>c[i][j];
	}
	for(i=0;i<h;i++)
	{
		for(j=0;j<w;j++)
		{
			if(c[i][j]=='#')
			dp[i][j]=0;
			else if(i==0&&j==0)
			dp[i][j]=1;
			else if(i==0)
			dp[i][j]=dp[i][j-1];
			else if(j==0)
			dp[i][j]=dp[i-1][j];
			else
			{
				dp[i][j]=dp[i-1][j]%1000000007+dp[i][j-1]%1000000007;
			    dp[i][j]=dp[i][j]%1000000007;
			}
			
		}
	}
	cout<<dp[h-1][w-1]%1000000007<<endl;
	return 0;
}