#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
using namespace std;
struct node{
	int y,next;
}a[800010];int len=0,last[400010];
int n,m,c[400010],dis[400010];
bool vis[400010];
char s[200010];
void ins(int x,int y)
{
	a[++len].y=y;
	a[len].next=last[x];last[x]=len;
}
void insert(int x,int y,int c)
{
	int X=x+n,Y=y+n;
	if(c==1) ins(x,Y),ins(y,X);
	else ins(X,y),ins(Y,x);
}
bool dfs(int x)
{
	if(vis[x]) return true;
	vis[x]=true;
	for(int i=last[x];i;i=a[i].next)
	{
		int y=a[i].y;
		if(dis[y]<dis[x]+1)
		{
			dis[y]=dis[x]+1;
			if(dfs(y)) return true;
		}
	}
	vis[x]=false;
	return false;
}
int main()
{
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) c[i]=s[i]-'A';
	for(int i=1;i<=m;i++)
	{
		int x,y;scanf("%d %d",&x,&y);
		//ins(x,y);ins(y,x);
		if(c[x]==c[y]) insert(x,y,1);
		else insert(x,y,0);
	}
	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
		if(dfs(i)) {printf("Yes");return 0;}
	printf("No");
}