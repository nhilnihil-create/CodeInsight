#include <bits/stdc++.h>
#define ll long long 
#define mp make_pair
using namespace std;
inline int read()
{
	int x=0,fl=1;char st=getchar();
	while(st<'0'||st>'9'){ if(st=='-')fl=-1; st=getchar();}
	while(st>='0'&&st<='9') x=x*10+st-'0',st=getchar();
	return x*fl;
}
const int N=1e5+10;
int d[N],v[N],n;
struct skr
{
	int to,nxt,v;
}a[N<<1];
int head[N],cnt;
inline void add(int x,int y,int z)
{
	a[++cnt].to=y;a[cnt].nxt=head[x];head[x]=cnt;a[cnt].v=z;
//	printf("%d->%d %d\n",x,y,z);
}
priority_queue<pair<int,int> >q;
void dij()
{
	memset(d,0x3f,sizeof d);
//		memset(v,0,sizeof v);
	d[1]=0;
	q.push(mp(0,1));
	while(q.size())
	{
		int x=q.top().second;q.pop();
		if(v[x]) continue;
		v[x]=1;
		for(int i=head[x];i;i=a[i].nxt)
		{
			int y=a[i].to;
			if(d[y]>d[x]+a[i].v)
			{
				d[y]=d[x]+a[i].v;
				q.push(mp(-d[y],y));
			}
		}
	}
}
int main()
{
	n=read();
	for(int i=0;i<n;i++)
		add(i,(i+1)%n,1);
	for(int i=0;i<n;i++) add(i,10*i%n,0);
	dij();
	printf("%d\n",d[0]+1);
	return 0;
}
