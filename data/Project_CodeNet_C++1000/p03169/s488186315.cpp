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

ld dp[305][305][305];

ld fxn(ll n1,ll n2,ll n3,ll n)
{
	if(dp[n1][n2][n3]!=-1.0)
	{
		return dp[n1][n2][n3];
	}
	ld p,pro1,pro2,pro3,d1,d2,d3;
	pro1=(ld)n1/n;
	pro2=(ld)n2/n;
	pro3=(ld)n3/n;
	p=pro1+pro2+pro3;
	if(p==0.0)
	{
		return 0;
	}
	if(n1==0)
	{
		d1=0;
	}
	else
	{
		d1=fxn(n1-1,n2,n3,n);
	}
	if(n2==0)
	{
		d2=0;
	}
	else
	{
		d2=fxn(n1+1,n2-1,n3,n);
	}
	if(n3==0)
	{
		d3=0;
	}
	else
	{
		d3=fxn(n1,n2+1,n3-1,n);
	}
	dp[n1][n2][n3]=((1/p)+((pro1*d1+pro2*d2+pro3*d3)/p));
	return dp[n1][n2][n3];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n1,n2,n3,n,i,j,k,x;
    ld ans;
    cin>>n;
    n1=0;
    n2=0;
    n3=0;
    for(i=0;i<n;i++)
    {
    	cin>>x;
    	if(x==1)
    	{
    		n1++;
    	}
    	else if(x==2)
    	{
    		n2++;
    	}
    	else
    	{
    		n3++;
    	}
    }
    for(i=0;i<305;i++)
    {
    	for(j=0;j<305;j++)
    	{
    		for(k=0;k<305;k++)
    		{
    			dp[i][j][k]=-1.0;
    		}
    	}
    }
    ans=fxn(n1,n2,n3,n);
    printf("%0.15Lf\n",ans);
	return 0;
}