#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
typedef pair<int,int> par;
int a[300000],n,k;
pair<par,par> dp[300000];
int main()
{
	cin>>n;
	for(int i=0;i<(1<<n);i++) cin>>a[i],dp[i]=mp(mp(a[i],i),mp(-1,-1));
	for(int i=1;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				if((i^(1<<j))==0)
				{
					if(dp[i].fi.fi>=dp[0].fi.fi)
					{
						dp[i].se.fi=dp[0].fi.fi;
						dp[i].se.se=0;
					}
					else
					{
						dp[i].se.fi=dp[i].fi.fi;
						dp[i].se.se=dp[i].fi.se;
						dp[i].fi.fi=dp[0].fi.fi;
						dp[i].fi.se=0;
					}
					continue;
				}
				if(dp[i].fi.fi==dp[i^(1<<j)].fi.fi&&dp[i].fi.se==dp[i^(1<<j)].fi.se) continue;
				if(dp[i].fi.fi<=dp[i^(1<<j)].fi.fi&&dp[i].fi.se!=dp[i^(1<<j)].fi.se)
				{				
					dp[i].se.fi=dp[i].fi.fi;
					dp[i].se.se=dp[i].fi.se;
					dp[i].fi.fi=dp[i^(1<<j)].fi.fi;
					dp[i].fi.se=dp[i^(1<<j)].fi.se;
					if(dp[i].se.fi==dp[i^(1<<j)].se.fi&&dp[i].se.se==dp[i^(1<<j)].se.se) continue;
					if(dp[i].se.fi<=dp[i^(1<<j)].se.fi&&dp[i].se.se!=dp[i^(1<<j)].se.se)
					{
						dp[i].se.fi=dp[i^(1<<j)].se.fi;
						dp[i].se.se=dp[i^(1<<j)].se.se;
					}
					continue;
				}
				else if(dp[i].se.fi==dp[i^(1<<j)].fi.fi&&dp[i].se.se==dp[i^(1<<j)].fi.se) continue;
				if(dp[i].se.fi<=dp[i^(1<<j)].fi.fi&&dp[i].se.se!=dp[i^(1<<j)].fi.se)
				{
					dp[i].se.fi=dp[i^(1<<j)].fi.fi;
					dp[i].se.se=dp[i^(1<<j)].fi.se;
				}
			}
		}
	}
	int mx=0;
	for(int i=1;i<(1<<n);i++)
	{
		mx=max(mx,dp[i].fi.fi+dp[i].se.fi);
		cout<<mx<<endl;
	}
}