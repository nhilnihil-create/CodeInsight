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

ll a[105];
ll dp[105][100005];

ll solve(ll n,ll k)
{
	if(k<0)
	{
		return 0;
	}
	if(n==0)
	{
		if(k<=a[0])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if(dp[n][k]!=-1)
	{
		return dp[n][k];
	}
	ll p,q,r;
	p=solve(n-1,k)%mod;
	q=solve(n,k-1)%mod;
	r=solve(n-1,k-1-a[n])%mod;
	dp[n][k]=(p+q-r+mod)%mod;
	return dp[n][k];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll N,K,i,j;
    cin>>N>>K;
    for(i=0;i<N;i++)
    {
    	cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    for(i=0;i<=K;i++)
    {
    	if(i<=a[0])
    	{
    		dp[0][i]=1;
    	}
    	else
    	{
    		dp[0][i]=0;
    	}
    }
    cout<<solve(N-1,K)<<"\n";
	return 0;
}