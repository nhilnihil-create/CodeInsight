#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
struct Point
{
	ll x,y;
}p[1005];
int n,m,d[105];
void solve(Point p,ll d)
{
	if(abs(p.x-d)+abs(p.y)<=d-1)p.x-=d,putchar('R');
	else if(abs(p.x+d)+abs(p.y)<=d-1)p.x+=d,putchar('L');
	else if(abs(p.x)+abs(p.y-d)<=d-1)p.y-=d,putchar('U');
	else if(abs(p.x)+abs(p.y+d)<=d-1)p.y+=d,putchar('D');
	if(d>1)solve(p,d/2);
}
int main()
{
	scanf("%d",&n);
	ll x=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld",&p[i].x,&p[i].y);
		if(((p[i].x+p[i].y)&1)!=((p[1].x+p[1].y)&1))return puts("-1"),0;
		x=max(x,abs(p[i].x)+abs(p[i].y));
	}
	bool flag=((p[1].x+p[1].y)%2==0);
	while((1ll<<m)<=x)m++;
	m++;
	if(flag)printf("%d\n1 ",m+1);
	else printf("%d\n",m);
	for(int i=m-1;i>=0;i--)printf("%lld ",1ll<<i);
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		if(flag)putchar('R'),p[i].x--;
		solve(p[i],1ll<<(m-1));
		putchar('\n');
	}
	return 0;
}