#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define endl '\n'
#define pb push_back
#define mod 1000000007
#define mp make_pair
#define pi acos(-1)
#define line cout<<"----------------------------"<<endl
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL)
#define filein freopen("input.txt","r",stdin)
#define fileout freopen("output.txt","w",stdout)
using namespace std;
const ll  mx=3009;
ll pre[1LL<<17]; 
int ara[17][17]; 
ll dp[1<<17] ; 
int main()
{
	fast; 
	int  n;
	cin>>n; 
	for(int  i=0;i<n;i++)
	{
		for(int  j=0;j<n;j++) cin>>ara[i][j];
	}
	for(int mask=0;mask<(1<<n);mask++)
	{
		for(int  j=0;j<n;j++)
		{
			if(mask&(1<<j))
			{
				for(int  k=j+1;k<n;k++)
				{
					if(mask&(1<<k))
					{
						pre[mask]+=ara[j][k]; 
					}
				}
			}
		}
	}
	
	for(int mask=0;mask<(1<<n);mask++)
	{
		dp[mask]=pre[mask]; 
		for(int i=mask;i;i=(i-1)&mask)
		{
			dp[mask]=max(dp[mask],dp[mask^i]+pre[i]);
		}
	}
	cout<<dp[(1LL<<n)-1]<<endl;
}
