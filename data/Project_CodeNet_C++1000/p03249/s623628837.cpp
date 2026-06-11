#include <cstring>
#include <bitset>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include<stdio.h>
#include<map>
#include<algorithm>
#include<cstdio>
#include <math.h>
#include<cmath>
#define inc(i,a,b) for(register int i=a;i<=b;i++)
#define dec(i,a,b) for(register int i=a;i>=b;i--)
using namespace std;
typedef long long LL;
inline void read(int &x)
{
	x=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=1;c=getchar();}
	while(c<='9'&&c>='0')x=(x<<3)+(x<<1)+c-'0',c=getchar();
	if(f)x=-x;return;
}
inline void read(LL &x)
{
	x=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=1;c=getchar();}
	while(c<='9'&&c>='0')x=(x<<3)+(x<<1)+c-'0',c=getchar();
	if(f)x=-x;return;	
}
const int mx=100007;
struct node
{
	int n,t,u;
}nx[mx];
int n,siz[mx],cnt,h[mx];
pair <LL,int> d[mx];
#define f first
#define s second
void add(int u,int v)
{
	nx[++cnt].n=h[u];
	nx[cnt].u=u;
	nx[cnt].t=v;
	h[u]=cnt;
}
int find(LL x)
{
	int l=1,r=n,mid=(l+r)>>1;
	while(l<=r)
	{
		if(d[mid].f==x)return mid;
		if(d[mid].f<x)l=mid+1;
		else r=mid-1;mid=(l+r)>>1;
	}
	return 0;
}
LL check;
#define link(i,x) for(register int i=h[x];i;i=nx[i].n)
LL dfs(int x,LL upp)
{
	LL res=upp;
	link(i,x)res+=dfs(nx[i].t,upp+1);
	return res;
}
int main()
{
	read(n);
	inc(i,1,n)
	{
		read(d[i].f);
		d[i].s=i;
		siz[i]=1;
	}
	sort(d+1,d+n+1);
	dec(i,n,2)
	{
		int fr=find(d[i].f+(siz[i]<<1)-n);
		if(fr)add(fr,i),siz[fr]+=siz[i];
		else {printf("-1\n");return 0;}
	}
	check=dfs(1,0);
	if(check!=d[1].f)
	{
		printf("-1\n");
		return 0;
	}
	inc(i,1,cnt)printf("%d %d\n",d[nx[i].u].s,d[nx[i].t].s);
}