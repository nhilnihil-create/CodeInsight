//Author: Rahul Purohit

#include<bits/stdc++.h>
#define vi vector<int>
#define rep(i,a,b) for(ll i=a;i<b;++i)
#define ll  long long int
#define pi pair<ll,ll>
#define f first
#define mp make_pair
#define mod 1000000007
#define s second
#define pb push_back
#define mp make_pair
using namespace std;
int gcd(int a, int b)
{
	if(b==0)
		return a;
	else
		return (b,a%b);
}
/*ll isp[N]={1};
void sieve(int n)
{
	isp[0]=isp[1]=0;
	for(int i=2;i<=n;i++)
	{
		if(isp[i]==1)
		{
			for(int j=i*i;j<=n;j+=i)
			{
				isp[j]==0;
			}
		}
	}
}*/
ll pow(int x,int  y,int m)
{
	ll ans=1;
	while(y!=0)
	{
		if(y%2==1)
		{
			ans=(ans*x)%m;
		}
		x=(x*x)%m;
		y/=2;
	}
	return ans;
}
template <class x>
void swap(x &a,x &b)
{
	x tp;
	tp=a;
	a=b;
	b=tp;
}
int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    ll n;
    cin>>n;
    cout<<(n-2)*180;
    return 0;
}
