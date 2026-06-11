#include<bits/stdc++.h>
#define ll long long
const ll inf=1e18L+5;
using namespace std;


int main()
{
	int n;
	cin>>n;
	vector<ll>a(n);
	vector<ll>s(n,0);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		if(i!=0)
			s[i]+=s[i-1]+a[i];
		else
			s[i]=a[i];
	}

	ll dp[402][402];
	for(int l=n-1;l>=0;l--)
	{
		for(int r=l;r<n;r++)
		{
			if(l==r)
			{
				dp[l][r]=0;
				continue;
			}
			dp[l][r]=inf;
			ll range=0;
			if(l-1>=0)
				range=s[r]-s[l-1];
			else
				range=s[r];
			for(int i=l;i<r;i++)
				dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]+range);
		}
	}
	cout<<dp[0][n-1];
}
