#include<bits/stdc++.h>
using namespace std;
int n,sum,a[2020];
bitset<4040404>dp,yl;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	dp|=1;
	for(int i=0;i<n;i++)
	{
		dp|=(dp<<a[i]);
	}
	for(int i=0;i<=sum;i++)
	{
		if(dp[i] && i>=(sum+1)/2)
		{
			cout<<i<<endl;
			return 0;
		}
	}
	return 0;
}