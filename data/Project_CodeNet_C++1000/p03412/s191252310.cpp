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
	//	int id = lower_bound(y.begin(),y.end(),left) - y.begin() - 1;
	//	if(id>=0)	res+=(ll)(id+1ll);
		while(j>=0&&x[i]+y[j]>=val)	j--;
		if(j>=0)	res += (ll)(j+1);	
	}
	return res;	
}
ll cnt(int L,int R)
{
	ll res = 0ll;
	int i,l=0,r=0;
	for(i=n-1;i>=0;i--)
	{
		while(r<n&&x[i]+y[r]<R)	r++;
		while(l<n&&x[i]+y[l]<L)	l++;
		res += (r-l);
	}
	return res;
}
bool solve(int t)
{
	ll b = 1ll<<t;
	return (cnt(b,b<<1)+cnt(3*b,b<<2))&1;
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
		ans += solve(i)<<i;
	//	res = f(4ll*(1ll<<i)) - f(3ll*(1ll<<i)) + f(2ll*(1ll<<i)) - f(1ll<<i);
	//	if(res%2ll==1ll)	ans += (1ll<<i);
	}
	printf("%lld",ans);
}
