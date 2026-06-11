#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mod 1000000007
#define pi  3.1415926535
int main()
{
	ll n,m,i,j,k;
	cin>>n>>k;
	ll a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	ll dp[k+1];
	dp[0]=0;
	for(i=1;i<=k;i++)
	{
		dp[i]=0;
		for(j=0;i>=a[j]&&j<n;j++)
		{
			if(!dp[i-a[j]])
			{
				dp[i]=1;
				break;
			}
		}
	}
	if(dp[k])
	cout<<"First\n";
	else
	cout<<"Second\n";
}
