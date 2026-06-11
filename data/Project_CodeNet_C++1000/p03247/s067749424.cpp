#include<bits/stdc++.h>
#define ll long long
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
#define dbg3(x) cerr<<#x<<"\n"
using namespace std;
#define int ll
#define reg register
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
const int MN=10005;
int N,X[MN],Y[MN];
int d[45],n;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
const char dc[4]={'D','L','U','R'};
void get(int x,int y)
{
	reg int i,j;
	for(i=n;~i;--i)for(j=0;j<4;++j)
	{
		int xx=x+dx[j]*d[i],yy=y+dy[j]*d[i];
		if(abs(xx)+abs(yy)<d[i]){x=xx,y=yy;printf("%c",dc[j]);j=5;}
	}
}
signed main()
{
	N=read();
	reg int i,mx=0;bool fl=1;
	for(i=1;i<=N;++i)
		X[i]=read(),Y[i]=read(),fl&=(~(X[i]+Y[i]-X[1]-Y[1])&1),
		mx=max(mx,abs(X[i])+abs(Y[i])+2);
	if(!fl) return 0*puts("-1");
	fl=~(X[1]+Y[1])&1;
	for(d[1]=n=1;(d[n]<<1)<mx;++n,d[n]=d[n-1]<<1);
	printf("%d\n",n+fl);
	if(fl) printf("1 ");
	for(i=1;i<=n;++i) printf("%d ",d[n-i+1]);puts("");
	for(i=1;i<=N;++i)
	{
		if(fl) printf("R");
		get(X[i]-fl,Y[i]);
		puts("");
	}
	return 0;
}