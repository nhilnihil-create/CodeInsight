#include<bits/stdc++.h>
#define mod 1e9+7
#define ll long long
using namespace std;


int main()
{
	
	int n,k;
	cin>>n>>k;
	vector<ll>a;
	for(int i=0;i<n;i++)
	{
		ll x;
		cin>>x;
		a.push_back(x);
	}
	sort(a.begin(),a.end());
	vector<ll>dp(k+1,0);
	vector<ll>p(k+1,1);
	dp[0]=1;

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			if(j==0)
			{	
				p[j]=dp[j]=1;
				 // cout<<dp[j]<<" :
				continue;
			}
			p[j]=(dp[j]+p[j-1])%(ll)(1e9+7);

			if(j-(a[i]+1)>=0)
				dp[j]=(p[j]-p[j-a[i]-1]+(ll)(1e9+7))%(ll)(1e9+7);
			else
				dp[j]=p[j];


			// cout<<dp[j]<<" ::"<<p[j]<<":: ";

		}
		// cout<<endl;
	}
	cout<<dp[k];	
}