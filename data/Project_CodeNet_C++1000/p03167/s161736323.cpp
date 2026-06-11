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
ll n,m;
ll dp[1001][1001];
char a[1001][1001];
ll getans(int i,int j)
{
	if(i>=n||j>=m)
	{
		return 0;
	}
	if(i==n-1&&j==m-1)
	{
		return 1;
	}
	if(a[i][j]=='#')
	{
		return 0;
	}
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	int ans=0;
	ans=(getans(i+1,j))%mod+(getans(i,j+1))%mod;
	return dp[i][j]=ans%mod;
}
int main()
{
ios::sync_with_stdio(false);
	 cin.tie(0);
    cout.tie(0);
memset(dp,-1,sizeof(dp));
cin>>n>>m;
for(int i=0;i<n;i++)
{
	for(int j=0;j<m;j++)
	{
		cin>>a[i][j];
	}
}
cout<<getans(0,0);
}



