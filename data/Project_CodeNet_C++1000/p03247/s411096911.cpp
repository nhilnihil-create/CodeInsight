#include<cstdio>
#include<iostream>
#include<cstring>
#define RG register
#define ll long long
using namespace std;
const int N=1e3+10;
int n,maxx=32;
ll pw[35]={1},d[35],x[N],y[N];
inline ll read(){
	char ch=getchar(); ll x=0, f=1;
	while(ch<'0' || ch>'9') {if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;}
inline ll abss(ll a){return a>0 ? a : -a;}
int main()
{
//	freopen("Robot Arms.in","r",stdin);
	//freopen(".out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)
	{
		x[i]=read(); y[i]=read();
		if((abss(x[i]+y[i])%2)!=(abss(x[1]+y[1])%2))
		{
			printf("-1\n");
			return 0;
		}
	}
	for(int i=1;i<=maxx;i++) pw[i]=pw[i-1]*2;
	for(int i=1;i<=maxx;i++)
	{
		d[i]=pw[maxx-i+1];
	}
	d[++maxx]=1;
	if((abss(x[1]+y[1]))%2==0)
	{
		d[++maxx]=1;
	}
	printf("%d\n",maxx);
	for(int i=1;i<=maxx;i++) printf("%lld ",d[i]); printf("\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=maxx;j++)
		{
			if(abss(x[i])>abss(y[i]))
			{
				if(x[i]>=0)
				{
					printf("R"), x[i]-=d[j];
				}
				else printf("L"), x[i]+=d[j];
			}
			else
			{
				if(y[i]>=0)
				{
					printf("U"), y[i]-=d[j];
				}
				else printf("D"), y[i]+=d[j];
			}
		}
		printf("\n");
	}
//	for(int i=1;i<=n;i++) printf("%lld %lld\n",x[i],y[i]);
	//fclose(stdin); fclose(stdout);
	return 0;
}