#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define int long long
#define pb push_back
#define mod 1000000007
#define setbits(x) __builtin_popcountll(x)
#define zerobits(x) __builtin_ctzll(x)
#define inf 1e18
#define pre(x,y) fixed<<setprecision(y)<<x
#define pq priority_queue<int>
#define mpq priority_queue<int,vector<int>,greater<int>>
#define gcd(x,y) __gcd(x,y)
#define mp make_pair

int p[21][21];
int dp[21][1<<21];

int matching(int n,int i,int mask)
{
	if(i==n)
	{
		if(mask==(1<<n)-1) return 1;
		else return 0;
	}
	else if(dp[i][mask]!=-1) return dp[i][mask];
	else
	{
		int ans=0;
		for(int j=0;j<n;j++)
		{
			if(p[i][j])
			{
				int tempmask=1<<j;
				if(!(tempmask&mask))
				{
					ans+=matching(n,i+1,mask|tempmask);
					ans%=mod;
				}
			}
		}
		return dp[i][mask]=ans;
	}
}


int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,i,j,k;
    cin>>n;
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n;j++) cin>>p[i][j];
    }
    memset(dp,-1,sizeof(dp));
    cout<<matching(n,0,0)<<endl;
	return 0;
}
