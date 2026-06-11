#include<bits/stdc++.h>
#define maxn 100005
using namespace std;
int n,m,f[maxn*3],e[maxn];
int getf(int x)
{
	if(f[x]==x)return x;
	return f[x]=getf(f[x]);
}
int main()
{
	int x,y,tx,ty,a,b,opt,ans=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n*3;i++)f[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d",&x,&y,&opt);opt%=2;
		tx=x+n;ty=y+n;a=getf(x+2*n);b=getf(y+2*n);
		f[a]=b;
		if(!opt)
		{
			if(getf(x)==getf(ty))printf("0"),exit(0);
			f[getf(x)]=getf(y);f[getf(tx)]=getf(ty);
		}
		else
		{
			if(getf(x)==getf(y))printf("0"),exit(0);
			f[getf(x)]=getf(ty);f[getf(tx)]=getf(y);
		}
	}
	for(int i=2*n+1;i<=3*n;i++)if(f[i]==i)ans++;
	printf("%d\n",ans);
	return 0;
}