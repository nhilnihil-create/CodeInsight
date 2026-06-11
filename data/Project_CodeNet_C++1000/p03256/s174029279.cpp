#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define M 500010
using namespace std;
 
int n,m,num,cnt;
int head[M],c[M],in[M][2];
char s[M];bool vis[M];
struct point{int to,next;}e[M<<1];
void add(int from,int to)
{
	e[++num].next=head[from];
	e[num].to=to;
	head[from]=num;
}

queue<int>q;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++) c[i]=s[i]-'A';
	for(int i=1;i<=m;i++)
	{
		int x,y;scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
		in[x][c[y]]++; in[y][c[x]]++;
	}
	for(int i=1;i<=n;i++)
		if(!in[i][0]||!in[i][1])
			q.push(i),cnt++,vis[i]=true;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].next)
		{
			int to=e[i].to;in[to][c[x]]--;
			if((!in[to][0]||!in[to][1])&&!vis[to])
				q.push(to),cnt++,vis[to]=true;
		}
	}
	printf(cnt==n?"No":"Yes");
	return 0;
}