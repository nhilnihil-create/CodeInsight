#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1100;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
const int Log=40;
int p2[Log];
char mp[4]={'U','D','R','L'};
int n;
int x[maxn],y[maxn];
int Abs(int x)
{
	if(x<0) return -x;
	return x;
}
int check()
{
	for(int i=2;i<=n;i++)
	{
		if(Abs(x[i]+y[i])%2!=Abs(x[i-1]+y[i-1])%2) return 0;
	}
	return 1;
}
int Ch(int x,int y,int k)
{
	int d1=Abs(x+y);
	int d2=Abs(x-y);
	if(d1>k||d2>k) return 0;
	return 1;
}
void put(int X,int Y,int k,int id)
{
	if(k==-1) return;
	int d=p2[k]-1;
	for(int i=0;i<=3;i++)
	{
		int nx=X+dx[i]*p2[k],ny=Y+dy[i]*p2[k];
		if(!Ch(nx-x[id],ny-y[id],d)) continue;
		printf("%c",mp[i]);
		put(nx,ny,k-1,id);
		break;
	}
	return;
}
signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld%lld",&x[i],&y[i]);
	if(!check()) return printf("-1\n"),0;
	p2[0]=1;
	for(int i=1;i<=30;i++) p2[i]=p2[i-1]*2;
	int op=Abs((x[1]+y[1])%2);
	op^=1;
	printf("%lld\n",31+op);
	if(op) printf("1 ");
	for(int i=30;i>=0;i--) printf("%lld ",p2[i]);
	printf("\n");
	for(int i=1;i<=n;i++)
	{
		if(op) printf("R");
		put(op,0,30,i);
		printf("\n");
	}
	return 0;
}


