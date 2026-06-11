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
string s,t;
int dp[3010][3010];
int getans(int i,int j)
{
	if(i>=s.size())
	{
		return 0;
	}
	if(j>=t.size())
	{
		return 0;
	}
	if(dp[i][j]!=-1)
	{
		return dp[i][j];
	}
	int ans=0;
	if(s[i]==t[j])
	{
		 ans=1+getans(i+1,j+1);

	}
	else
	{
		 ans=max(getans(i+1,j),getans(i,j+1));
	}
	return dp[i][j]=ans;
}
void path(int i,int j)
{
		if(i>=s.size())
	{
		return ;
	}
	if(j>=t.size())
	{
		return ;
	}
	int d=getans(i,j);
	if(s[i]==t[j])
	{
		cout<<s[i];
		return path(i+1,j+1);
	}
	else
	{
		if(d==getans(i+1,j))
		{
			return path(i+1,j);
		}
		return path(i,j+1);
	}
}
int main(){
cin>>s>>t;
	memset(dp,-1,sizeof(dp));
int v=getans(0,0);
path(0,0);
}


