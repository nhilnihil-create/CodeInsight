#include<bits/stdc++.h>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,i,k;
	cin>>n>>k;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	bool dp[k+1];
	memset(dp,0,sizeof(dp));
	for(i=0;i<=k;i++)
	{
		int j;
		for(j=0;j<n;j++)
		{
			if(a[j]<=i)
				dp[i]|=(!dp[i-a[j]]);
		}
	}
	if(dp[k]==1)
		cout<<"First"<<endl;
	else
		cout<<"Second"<<endl;
	return 0;
}