#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e3+20;

ll x[maxn],y[maxn];
int n;
int X[maxn],Y[maxn];
int m;
ll d[maxn],suf[maxn];

inline void init()
{
	n=read();
	REP(i,1,n)x[i]=read(),y[i]=read();
	int t=0;
	t=x[1]+y[1]&1;
	REP(i,2,n)if(x[i]+y[i]-t&1)puts("-1"),exit(0);
	REP(i,0,30)d[++m]=1<<30-i;
	if(!t)d[++m]=1;
	DREP(i,m,1)suf[i]=suf[i+1]+d[i];
	printf("%d\n",m);
	REP(i,1,m)printf("%d ",d[i]);puts("");
}

inline void doing()
{
	REP(i,1,n)
	{
		REP(j,1,m)
		{
			if(abs(x[i]-d[j])+abs(y[i])<=suf[j+1])x[i]-=d[j],putchar('R');
			else if(abs(x[i]+d[j])+abs(y[i])<=suf[j+1])x[i]+=d[j],putchar('L');
			else if(abs(x[i])+abs(y[i]-d[j])<=suf[j+1])y[i]-=d[j],putchar('U');
			else y[i]+=d[j],putchar('D');
		}
		puts("");
	}
}

int main()
{
	init();
	doing();
	return 0;
}

