#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll N=1e6+5,inf=1e18,mod=1e9+7;
#define test ll testcases;cin>>testcases; while(testcases--)
#define lp(var,start,end) for (ll var = start; var <end ; ++var)
#define rlp(var,start,end) for(ll var = start; var>=end ; var--)
#define pb push_back
#define mp make_pair
#define pf push_front
#define ff first
#define ss second
#define vll vector<ll>
#define vld vector<ld>
#define pll pair<ll,ll> 
#define pld pair<ld,ld> 
#define vpll vector<pll>
#define vpld vector<pld>
#define all(X) X.begin(),X.end()
#define sz(x) ((ll)((x).size()))
const ld pi=3.141592653589793238;

bool check_prime(ll n)
{
	ll flag=0,i;
	for(i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			flag=1;
			break;
		}
	}
	if(n==1)
	{
		return false;
	}
	else if(flag==0 || n==2 || n==3)
	{
		return true;
	}
	else
	{
		return false;
	}
}

ll fastexpo(ll a,ll b,ll MOD) 
{
	ll result=1;
	while(b>0)
	{
		if(b%2==1)
		{
			result=(result*a)%MOD;
		}
		a=(a*a)%MOD;
		b=b/2;
	}
	return result;
}

vll G[N];
ll 	dp[N][2];

ll dfs(ll node,ll parent,ll k)
{
	if(sz(G[node])==1 && node!=1)
	{
		dp[node][k]=1;
		return 1;
	}
	if(dp[node][k]!=-1)
	{
		return dp[node][k];
	}
	ll i,ans=1;
	for(i=0;i<sz(G[node]);i++)
	{
		if(parent!=G[node][i])
		{
			if(k==0)
			{
				ans=(ans*(dfs(G[node][i],node,0)+dfs(G[node][i],node,1)))%mod;
			}
			else
			{
				ans=(ans*dfs(G[node][i],node,0))%mod;
			}
		}
	}
	dp[node][k]=ans;
	return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,i,u,v,ans,k1,k2;
    cin>>n;
    for(i=1;i<n;i++)
    {
    	cin>>u>>v;
    	G[u].pb(v);
    	G[v].pb(u);
    }
    memset(dp,-1,sizeof(dp));
    k1=dfs(1,1,0);
    k2=dfs(1,1,1);
    ans=(k1+k2)%mod;
    cout<<ans<<"\n";
	return 0;
}