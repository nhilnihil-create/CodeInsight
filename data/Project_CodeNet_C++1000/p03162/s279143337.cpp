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
ll a[100010][4];
ll dp[100010][4];
ll getans(ll i,ll k)
{
if(i>n)
{
	return 0;
}
if(dp[i][k]!=-1)
{
	return dp[i][k];
}
ll ans=0;
for(ll p=1;p<=3;p++)
{
	if(k!=p)
	ans=max(ans,getans(i+1,p)+a[i][p]);
}
return dp[i][k]=ans;
}
int main()
{
ios::sync_with_stdio(false);
	 cin.tie(0);
    cout.tie(0);
cin>>n;
for(ll i=1;i<=n;i++)
{
	for(ll j=1;j<=3;j++)
	cin>>a[i][j];
}
memset(dp,0,sizeof(dp));
dp[1][1]=a[1][1];
dp[1][2]=a[1][2];
dp[1][3]=a[1][3];
for(ll i=2;i<=n;i++)
{
dp[i][1]=max(dp[i-1][2]+a[i][1],dp[i-1][3]+a[i][1]);
dp[i][2]=max(dp[i-1][1]+a[i][2],dp[i-1][3]+a[i][2]);
dp[i][3]=max(dp[i-1][2]+a[i][3],dp[i-1][1]+a[i][3]);
}
ll ans=max(dp[n][1],max(dp[n][2],dp[n][3]));
cout<<ans<<endl;
}


