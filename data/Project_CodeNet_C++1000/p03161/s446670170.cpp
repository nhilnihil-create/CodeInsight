#include<bits/stdc++.h>
#include<cmath>
#define SZ(x) ((int)x.size())
#include<vector>
#include<set>
#include<map>
#define ll long long
#define lli long long int
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define pb push_back
#include<string>
#include<cctype>
#include<queue>
#define ii pair<int,int>
#include <sstream>
#define lli long long int
#define pairs pair<int,int>
#define mod 1000000007
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
using namespace std;
ll pows(ll a,ll n,ll m)
{
	ll res=1;
	while(n)
	{
	if(n%2!=0)
	{
		res=(res*a)%m;
		n--;
		}
		else
		{
			a=(a*a)%m;
			n=n/2;
			}	
	}
	return res%m;
}
ll  gcd(ll a,ll b)
{
	if(b==0)
	return a;
	else 
	return gcd(b,a%b);
}
bool isprime(ll n)
{
	if(n==1)
	{
		return false;
	}
	for(ll i=2;i*i<=n;i++)
	{
		if(n%i==0)
		{
			return false;
		}
	}
	return true;
}
bool istrue(string s)
{
	int i=0;
	int j=s.size()-1;
	while(i<j)
	{
	if(s[i]==s[j])
	{
		i++;
		j--;
		}
		else
		{
			return false;
			}	
	}
	return true;
}
ll n;
ll a[100001];
ll k;
ll dp[100001];
ll getans(ll i)
{
if(i>=n-1)
{
	return 0;
	}
	if(dp[i]!=-1)
	{
		return dp[i];
	}
	ll ans=mod;
	if(i+1<=n-1)
	{
		ans=min(ans,getans(i+1)+abs(a[i]-a[i+1]));
	}
	if(i+2<=n-1)
	{
		ans=min(ans,getans(i+2)+abs(a[i]-a[i+2]));
	}
return dp[i]=ans;
}
int main()
{
ios::sync_with_stdio(false);
	 cin.tie(0);
    cout.tie(0);
cin>>n;
cin>>k;

for(ll i=0;i<n;i++)
{
	cin>>a[i];
}
memset(dp,0,sizeof(dp));
if(n==1)
{
	cout<<0<<endl;
	return 0;
}
dp[0]=0;
for(ll i=1;i<n;i++)
{
	dp[i]=1e10;
	for(ll j=1;j<=k;j++)
	{
if(i-j>=0)
{
	dp[i]=min(dp[i],dp[i-j]+abs(a[i]-a[i-j]));
}
	}
}
cout<<dp[n-1]<<endl;
}



