#include<iostream>
using namespace std;
#include<map>
#include<cmath>
#include<algorithm>
#define int long long int
#define mod 1000000007
int power(int a,int b)
{
	if(b==0)
	  return 1;
	else
	{
		int r=power(a,b/2);
		if(b%2==0)
		{
			return (r*r)%mod;
		}
		else
		{
			int x=(r*r)%mod;
			return (a*x)%mod;
		}
	}
}
int function(int n,int val)
{
	if(n==0)
	   return 1;
	else
	{
		int p=-1;
		int j;
		for(j=0;j<val;j++)
		{
			int x=power(3,j);
			if(x<=n)
			{
				p=j;
			}
			else
			  break;
		}
		if(p==-1)
		  return 1;
		int here=power(2,p);
		if(power(3,p)==n)
		  return 1+here;
		here+=function(n-power(3,p),p);
		return here;
	}
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	int arr[n+1],j;
	for(j=0;j<n;j++)
	  cin>>arr[j+1];
	int prefix[n+1]={0};
	int suffix[n+2]={0};
	for(j=1;j<=n;j++)
	{
		prefix[j]=__gcd(arr[j],prefix[j-1]);
	}
	for(j=n;j>=1;j--)
	{
		suffix[j]=__gcd(arr[j],suffix[j+1]);
	}
	int answer=0;
	for(j=1;j<=n;j++)
	{
		int val=__gcd(prefix[j-1],suffix[j+1]);
		answer=max(answer,val);
	}
	cout<<answer<<endl;
}
