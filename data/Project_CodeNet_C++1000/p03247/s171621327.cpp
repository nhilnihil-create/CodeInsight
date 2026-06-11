#include<bits/stdc++.h>
using namespace std;

const long long inf=1ll<<40;
char p[2][2],ans[35];
int n,x[1010],y[1010],m;
long long d[35];

void solve(long long x,long long y)
{
	int i=1,px,py;
	long long nwx=0,nwy=0;
	p[0][0]='L',p[0][1]='D',p[1][0]='U',p[1][1]='R';
	if (!(x&1)) ans[0]=p[1][1],nwx++,nwy++,i++,ans[0]=p[1][1];
	for (; i<m; i++)
	{
		if ((nwx+d[i]+inf)%(4*d[i])==(x+inf)%(4*d[i])) px=0,nwx-=d[i]; else px=1,nwx+=d[i];
		if ((nwy+d[i]+inf)%(4*d[i])==(y+inf)%(4*d[i])) py=0,nwy-=d[i]; else py=1,nwy+=d[i];
		ans[i-1]=p[px][py];
	}
	if (nwx+d[m]==x) px=1; else px=0;
	if (nwy+d[m]==y) py=1; else py=0;
	ans[m-1]=p[px][py],puts(ans);
}

int main()
{
	scanf("%d",&n),m=0;
	for (int i=1; i<=n; i++) scanf("%d%d",&x[i],&y[i]);
	for (int i=1; i<n; i++) if (((x[i]+y[i])&1)!=((x[i+1]+y[i+1])&1)) return puts("-1"),0;
	if (!((x[1]+y[1])&1)) d[++m]=1;
	for (int i=0; i<=30; i++) d[++m]=(1ll<<i);
	printf("%d\n",m);
	for (int i=1; i<=m; i++) printf("%lld ",d[i]); puts("");
	for (int i=1; i<=n; i++) solve(x[i]+y[i],x[i]-y[i]);
	return 0;
}