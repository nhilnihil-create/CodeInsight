#include<cstdio>
#include<cstdlib>
#define llong long long
#define ldouble long double
#define uint unsigned int
#define ullong unsigned long long
#define udouble unsigned double
#define uldouble unsigned long double
#define modinc(x) {if(x>=P) x-=P;}
#define pii pair<int,int>
#define piii pair<pair<int,int>,int>
#define piiii pair<pair<int,int>,pair<int,int> >
#define pli pair<llong,int>
#define pll pair<llong,llong>
using namespace std;

const int N = 1e3;
struct Point
{
	llong x,y;
} a[N+3];
llong ans[N+3];
int n,m;

llong absl(llong x) {return x>=0 ? x : -x;}
llong dist(llong x,llong y) {return absl(x)+absl(y);}

void dfs(llong x,llong y,int dep)
{
//	printf("dfs%lld %lld %d\n",x,y,dep);
	if(dep==-1) return;
	llong lmt = (1ll<<dep)-1,dlt = (1ll<<dep);
	if(dist(x+dlt,y)<=lmt)
	{
		dfs(x+dlt,y,dep-1); printf("L");
	}
	else if(dist(x-dlt,y)<=lmt)
	{
		dfs(x-dlt,y,dep-1); printf("R");
	}
	else if(dist(x,y+dlt)<=lmt)
	{
		dfs(x,y+dlt,dep-1); printf("D");
	}
	else if(dist(x,y-dlt)<=lmt)
	{
		dfs(x,y-dlt,dep-1); printf("U");
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%lld%lld",&a[i].x,&a[i].y);
	int tmp = (a[1].x+a[1].y)&1;
	for(int i=2; i<=n; i++)
	{
		if(((a[i].x+a[i].y)&1)!=tmp)
		{
			printf("-1\n");
			return 0;
		}
	}
	if(!(tmp&1)) {for(int i=1; i<=n; i++) a[i].y--; ans[1] = 1ll; printf("32\n1 ");}
	else printf("31\n");
	for(int i=0; i<=30; i++) printf("%lld ",(1ll<<i)); puts("");
	for(int i=1; i<=n; i++)
	{
		if(!(tmp&1)) {printf("U");}
		dfs(a[i].x,a[i].y,30); puts("");
	}
	return 0;
}