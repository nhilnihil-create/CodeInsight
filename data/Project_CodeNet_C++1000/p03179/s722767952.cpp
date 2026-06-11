#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
#define pb push_back
#define maxm 1e18
#define minm -1e18
#define pr pair<ll,ll>
#define mod 1000000007
#define N 3001
ll dp[N][N];

void add_self(ll &a,ll b)
{
	a=(a+b)%mod;
}

/*O(n^3) - complexity
void solve()
{
	ll n,len,a,b,i;
	cin>>n;
	string cmp;
	cin>>cmp;
	dp[1][1]=1;
	//dp[i][j] -> number of ways to put numbers in
	//prefix of size 'i' such that last number is 'j5'
	
	for(len=2;len<=n;len++)
	{
		for(b=1;b<=len;b++)
		{
			for(a=1;a<=len-1;a++)
			{
				ll real_a=a;
				if(a>=b)
					real_a++;
				if((real_a<b)!=(cmp[len-2]=='<'))	continue;
				add_self(dp[len][b],dp[len-1][a]);
			}
		}
		cout<<"len is "<<len<<endl;
		for(i=1;i<=n;i++)
			cout<<dp[len][i]<<" ";
		cout<<endl;
	}
	ll ans=0;
	for(i=1;i<=n;i++)
		add_self(ans,dp[n][i]);
	cout<<ans<<endl;
}*/

//O(n^2) - complexity
void solve()
{
	ll n,len,a,b,i,l,r;
	cin>>n;
	string cmp;
	cin>>cmp;
	dp[1][1]=1;
	//dp[i][j] -> number of ways to put numbers in
	//prefix of size 'i' such that last number is 'j'
	for(len=2;len<=n;len++)
	{
		ll prefix[n+1];
		prefix[0]=0;
		for(b=1;b<len;b++)
			prefix[b]=(prefix[b-1]+dp[len-1][b]);
		for(b=1;b<=len;b++)
		{
			
			if(cmp[len-2]=='>'){
				l=1,r=b-1;
			}
			else{
				l=b,r=len-1;
			}
			if(l<=r)
				add_self(dp[len][b],(mod-prefix[l-1]+prefix[r]));
		}
	}
	ll ans=0;
	for(i=1;i<=n;i++)
		add_self(ans,dp[n][i]);
	cout<<ans<<endl;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    	ll t=1;
	//cin>>t;
	while(t--)
	{
		solve();
	}
	return 0;
}