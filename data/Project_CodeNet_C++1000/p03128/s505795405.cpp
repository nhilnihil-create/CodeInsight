#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,m,use[9]={2,5,5,4,5,6,3,7,6};
	cin>>n>>m;
	int a[m],mi=10,b=-1,memo[10]={};
	for (int i = 0; i < m; ++i)
	{
		cin>>a[i];--a[i];
		memo[a[i]+1]=1;
		if (mi>=use[a[i]])
		{
			mi=use[a[i]];
			b=max(b,a[i]+1);
		}
	}
	sort(a,a+m);
	reverse(a,a+m);
	int dp[n+20];
	for (int i = 0; i < n+20; ++i)
	{
		dp[i]=-1000000;
	}
	dp[0]=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			dp[i+use[a[j]]]=max(dp[i+use[a[j]]],dp[i]+1);
		}
	}
	string ans="";
	while (n>0)
	{
		for (int i = 0; i < m; ++i)
		{
			if (n-use[a[i]]>=0&&dp[n]-1==dp[n-use[a[i]]])
			{
				ans+='1'+a[i];
				n-=use[a[i]];
				break;
			}
		}
	}
	sort(ans.begin(), ans.end());
	reverse(ans.begin(), ans.end());
	cout<<ans<<endl;
	return 0;
}
