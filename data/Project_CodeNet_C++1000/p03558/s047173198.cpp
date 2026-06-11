#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define For(i,a,b) for(register int i=(a);i<=(b);++i)
#define Rep(i,a,b) for(register int i=(a);i>=(b);--i)
using namespace std;
inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}
#define maxn 100007
int k,dis[maxn];
bool inq[maxn];
queue<int>q;
inline void relax(int u,int v,int w){
	if(dis[v]>dis[u]+w){
		dis[v]=dis[u]+w;
		q.push(v);
		if(!inq[v])inq[v]=1,q.push(v);
	}
} 
int spfa()
{
	memset(dis,63,sizeof dis);
	dis[1]=1;q.push(1);
	while(!q.empty())
	{
		int u=q.front();q.pop();inq[u]=0;
		relax(u,(u+1)%k,1);
		relax(u,u*10%k,0);
	}return dis[0];
}
int main()
{
	k=read();
	cout<<spfa(); 
    return 0;
}