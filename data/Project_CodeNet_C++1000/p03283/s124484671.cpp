#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int dp[502][502];
int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
		freopen("out","w", stdout);
	#endif
	int n,m,q;
	cin>>n>>m>>q;

	int l,r;
	for(int i=0;i<m;i++)
	{
		cin>>l>>r;
		dp[l][r]++;
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i][j]+=dp[i][j-1];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)dp[i][j]+=dp[i-1][j];
	//cout<<"ff";

	while(q--)
	{
		cin>>l>>r;


		cout<<dp[r][r]+dp[l-1][l-1]-(dp[l-1][r]+dp[r][l-1])<<"\n";
	}


	

}