#include <iostream>
using namespace std;
int n,a[25][25],dp[5000000];
const int MOD=1e9+7;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		cin>>a[i][j];
	dp[0]=1;
	for(int i=0;i<(1<<n);i++)
	{
		int x=__builtin_popcount(i);
		for(int j=0;j<n;j++)
		{
			if(a[x][j]==1&&!(i&1<<j))
			{
				int m2=i^1<<j;
				dp[m2]+=dp[i];
				dp[m2]%=MOD;	
			}
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}