#include <bits/stdc++.h>
#define int long long
using namespace std;

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
const int ps=33;
int n,X[1010],Y[1010];
int pw[ps];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int trs[4]={'D','U','L','R'};
int Ans[1010][40];
inline void swic(int i,int ts,int es)
{
	if(ts>=es) return;
	int sx;
	if(Ans[i][ts]=='R') sx='L',Ans[i][es]='R';
	if(Ans[i][ts]=='L') sx='R',Ans[i][es]='L';
	if(Ans[i][ts]=='U') sx='D',Ans[i][es]='U';
	if(Ans[i][ts]=='D') sx='U',Ans[i][es]='D';
	for(int j=ts;j<es;j++) Ans[i][j]=sx;
}
signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
		X[i]=read(), Y[i]=read();
	int op=(X[1]+Y[1])&1;
	for(int i=1;i<=n;i++)
		if(op^((X[i]+Y[i])&1))
		{
			puts("-1");
			exit(0);
		}	
	printf("%lld\n",ps-op);
	pw[0]=1; pw[1]=1;
	for(int i=2;i<ps;i++) pw[i]=pw[i-1]*2;
	for(int i=op;i<ps;i++)
		printf("%lld ",pw[i]); puts("");
	if(!op) for(int i=1;i<=n;i++)
		X[i]++,Ans[i][0]='L';
	for(int i=ps-1;i>=1;i--)
	{
		for(int j=1;j<=n;j++)
		{
			int sx=X[j],sy=Y[j];
			for(int k=0;k<4;k++)
			{
				int vx=sx+dir[k][0]*pw[i],
					vy=sy+dir[k][1]*pw[i];
				if(abs(vx)+abs(vy)<=pw[i])
				{
					X[j]=vx; Y[j]=vy;
					Ans[j][i]=trs[k];
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<ps;j++)
		{
			int tj=j+1;
			while(!Ans[i][tj]&&tj<ps) tj++;
			swic(i,j,tj-1);
			j=tj-1;
		}
		for(int j=op;j<ps;j++)
			putchar(Ans[i][j]);
		puts("");
	}
	return 0;
}