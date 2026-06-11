#include <bits/stdc++.h>
using namespace std;
#define N 200100

struct edge {int nex,to;}e[N<<1];
int n,m,cnt,he,ta;
char s[N];
int sum[N][2],head[N],q[N],inq[N];

void add(int x,int y) {e[++cnt].to=y; e[cnt].nex=head[x]; head[x]=cnt;}

int x,y;
int main()
{
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for (int i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		sum[x][s[y]-'A']++;
		sum[y][s[x]-'A']++;
		add(x,y); add(y,x);
	}
	for (int i=1;i<=n;i++)
		if (!sum[i][0] || !sum[i][1]) {
			q[++ta]=i;
			inq[i]=1;
		}
	
	while (he<ta)
	{
		int x=q[++he];
		for (int i=head[x];i;i=e[i].nex)
		{
			int v=e[i].to;
			if (!inq[v])
				if (--sum[v][s[x]-'A']==0) 
					q[++ta]=v,inq[v]=1;
		}
	}
	
	for (int i=1;i<=n;i++)
		if (!inq[i])
			return puts("Yes"),0;
	return puts("No"),0;
}