#include<bits/stdc++.h>
#define re register
int x[1010],y[1010],xa[]={0,1,-1,0,0},ya[]={0,0,0,1,-1};
char cc[]={0,'L','R','D','U'};
void dfs(re int i,re int xx,re int yy)
{
	if(i<0&&xx==0&&yy==0)return;
	for(re int i1=1;i1<=4;i1++)
	{
		re int x1=xx+((i==31)?1:(1<<i))*xa[i1];
		re int yy1=yy+((i==31)?1:(1<<i))*ya[i1];
		if(abs(x1)+abs(yy1)<(1u<<i))
		{
			putchar(cc[i1]);
			dfs(i-1,x1,yy1);
			return;
		}
	}
}
int main()
{
	re int n,xp=-1;
	scanf("%d",&n);
	for(re int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		if(xp==-1)xp=abs(x[i]+y[i])&1;
		else if(xp!=(abs(x[i]+y[i])&1))puts("-1"),exit(0);
	}
	printf("%d\n",32-xp);
	if(!xp)printf("1 ");
	for(re int i=30;i>=0;i--)printf("%d ",1<<i);puts("");
	for(re int i=1;i<=n;i++)
	{
		dfs(30+(!xp),x[i],y[i]);
		puts("");
	}
}