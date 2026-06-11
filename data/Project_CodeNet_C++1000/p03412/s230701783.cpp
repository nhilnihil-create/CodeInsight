#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
typedef pair<ll,ll> pll;
vector<ll> a,b,x,y;
const int L = 29;
int n;
ll f(ll val)
{
	int i,j=n-1;
	ll res=0ll;
	for(i=0;i<n;i++)
	{
		ll left = val - x[i];
		while(j>=0&&x[i]+y[j]>=val)	j--;
		if(j>=0)	res += (ll)(j+1);	
	}
	return res;	
}
int main()
{
	int i,j;
	scanf("%d",&n);
	a.resize(n);b.resize(n);x.resize(n);y.resize(n);
	ll ans = 0ll,res;
	for(i=0;i<n;i++)	scanf("%lld",&a[i]);
	for(i=0;i<n;i++)	scanf("%lld",&b[i]);
	for(i=0;i<L;i++)
	{
		for(j=0;j<n;j++)
		{
			x[j] = a[j] % (1ll<<(i+1));
			y[j] = b[j] % (1ll<<(i+1));	
		}
		sort(x.begin(),x.end());sort(y.begin(),y.end());
		res = f(4ll*(1ll<<i)) - f(3ll*(1ll<<i)) + f(2ll*(1ll<<i)) - f(1ll<<i);
		if(res%2ll==1ll)	ans += (1ll<<i);
	}
	printf("%lld",ans);
}
