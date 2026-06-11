#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<sys/time.h>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int ri()
{
	register int x=0;register bool f=0;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();};
	return f?-x:x;
}
void wi(int x)
{
	if(x<0)	x=-x,putchar('-');
	if(x>9)	wi(x/10);
	putchar('0'+x%10);
}
const int N=100005,M=N*2;
int head[N],to[M<<1],nxt[M<<1],val[M<<1];
int num[N],vis[N],x1[M],x2[M],d[M];
inline void ade(int x,int y,int z)
{
	nxt[++nxt[0]]=head[x];
	head[x]=nxt[0];
	to[nxt[0]]=y;
	val[nxt[0]]=z;
}
void dfs(int x)
{
	vis[x]=1;
	for(int now=head[x];now;now=nxt[now])
	{
		if(vis[to[now]])	continue;
		num[to[now]]=num[x]+val[now];
		dfs(to[now]);
	}
}
int main()
{
	int n=ri(),m=ri(),i;
	for(i=1;i<=m;i++)
	{
		x1[i]=ri(),x2[i]=ri(),d[i]=ri();
		ade(x1[i],x2[i],d[i]);ade(x2[i],x1[i],-d[i]);
	}
	for(i=1;i<=n;i++)	if(!vis[i])	dfs(i);
	for(i=1;i<=m;i++)
	{
		if(num[x2[i]]!=num[x1[i]]+d[i])
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}
