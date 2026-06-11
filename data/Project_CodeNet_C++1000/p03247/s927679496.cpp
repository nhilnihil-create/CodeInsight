# include <cstdio>
# include <iostream>
# include <cstring>
# include <cmath>
# include <algorithm>
# include <string>
# define ll long long
# define R register int
 
using namespace std;
 
const int maxn=1003;
int n,m,f=-1;
ll x[maxn],y[maxn];
ll d[35],len;
 
inline ll ab (ll x) { if(x<0) return -x; return x; }
 
inline void solve (ll x,ll y)
{
	for (R i=1;i<=m-((f&1)^1);++i)
	{
		if(ab(x)>ab(y))
		{
			if(x>0) putchar('R'),x-=d[i];
			else putchar('L'),x+=d[i];
		}
		else
		{
			if(y>0) putchar('U'),y-=d[i];
			else putchar('D'),y+=d[i];
		}
	}
	if(f%2==0) putchar('L');
	putchar('\n');
}
 
int main()
{
	scanf("%d",&n);
	for (R i=1;i<=n;++i)
	{
		scanf("%lld%lld",&x[i],&y[i]);
		len=ab(x[i])+ab(y[i]);
		if(f==-1) f=len%2;
		if(f%2!=len%2)
		{
			printf("-1");
			return 0;
		}
	}
	for (R i=30;i>=0;--i) d[++m]=(1LL<<i);
	if(f%2==0) d[++m]=1;
	printf("%d\n",m);
	for (R i=1;i<=m;++i)
    {
    	printf("%lld",d[i]);
		if(i==m) printf("\n");
		else printf(" ");
	}
	for (R i=1;i<=n;++i)
		solve(x[i]+((f&1)^1),y[i]);
	return 0;
}