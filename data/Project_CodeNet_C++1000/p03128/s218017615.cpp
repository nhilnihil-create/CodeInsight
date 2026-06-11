#include<bits/stdc++.h>
using namespace std;

// macro
#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define all(v) v.begin(), v.end()

// code starts
int main()
{
	int n,m;cin>>n>>m;
	vector<int> a(m);
	int i,j;
	rep(i,m)cin>>a[i];
	sort(all(a));
	reverse(all(a));
	vector<int> cost={100,2,5,5,4,5,6,3,7,6};
	vector<int> dp(n+1,-100);
	dp[0]=0;
	for(i=1;i<=n;i++)
	{
		rep(j,m)
		{
			if(i-cost[a[j]]>=0)
			{
				if(dp[i-cost[a[j]]]<0)continue;
				dp[i]=max(dp[i],dp[i-cost[a[j]]]+1);
			}
		}
	}
	int now=n;
	while(now>0)
	{
		rep(i,m)
		{
			if(now-cost[a[i]]<0)continue;
			if(dp[now]==1)
			{
				if(now==cost[a[i]])
				{
					cout<<a[i];
					now-=cost[a[i]];
					break;
				}
			}
			else if(dp[now-cost[a[i]]]==dp[now]-1)
			{
				cout<<a[i];
				now-=cost[a[i]];
				break;
			}
		}
	}
	cout<<endl;
}
