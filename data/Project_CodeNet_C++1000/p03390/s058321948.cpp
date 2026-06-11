#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define ll long long
#define pb(x) push_back(x)
#define mp(a,b) make_pair(a,b)
#define fi first
#define se second
#define pr(x) cerr<<#x<<"="<<(x)<<endl
#define pri(x,lo) {cerr<<#x<<"={";for (int ol=0;ol<=lo;ol++)cerr<<x[ol]<<",";cerr<<"}"<<endl;}
#define inf 100000000
#define N 1000
ll a,b,ans;
bool calc(ll xl,ll yl,ll len)
{
	ll xr=xl+len,yr=yl-len;
	if (xr<=yr) return xr*yr<a*b;
	if (xl>=yl) return xl*yl<a*b;
	ll t=(yl+xl)/2;
//	pr(666);
//	pr(t);
	if ((yl-xl)%2==0) return t*t<a*b;
	else return t*(t+1)<a*b;
}
bool check(ll x)
{
	ll y=x;x=1;
	ll o=a-1,p=x-b+1;
	//pr(o),pr(p);
	if (p<=0) 
	{
		if (calc(x,y,o)==0) return 0;
		x+=o,y-=o;x++; 
		if (calc(x,y,y)==0) return 0;
	}
	return 1;		
}
int main()
{
	int T;
	scanf("%d",&T);
	while (T--)
	{
		scanf("%lld %lld",&a,&b);
		if (a>b) swap(a,b);
		ll l=a-1,r=a-1+b-1;
		//pr(calc(9,35,35));return 0;
		//pr(check(42));return 0;
		while (l<=r)
		{
			ll mid=(l+r)/2;
			if (check(mid)) ans=mid,l=mid+1;
			else r=mid-1;
		}
		printf("%lld\n",ans);
	}
}