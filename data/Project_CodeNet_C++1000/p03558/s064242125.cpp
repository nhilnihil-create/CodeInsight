#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define pb push_back
#define pf push_front
#define Pf pop_front
#define MN 100005
using namespace std;
inline int in(){
    int x=0;bool f=0;char c;
    for (;(c=getchar())<'0'||c>'9';f=c=='-');
    for (x=c-'0';(c=getchar())>='0'&&c<='9';x=(x<<3)+(x<<1)+c-'0');
    return f?-x:x;
}
deque <int> q;
int dis[MN],k;
bool vis[MN];
int main()
{
	k=in();memset(dis,0x3f,sizeof(dis));
	dis[1]=0;q.pb(1);
	while (!q.empty()){
		int u=q.front();q.Pf();
		if (vis[u]) continue;
		if (!u) break;vis[u]=1;int v=(10*u)%k;
		if (dis[v]>dis[u]) dis[v]=dis[u],q.pf(v);
		v=(u+1==k)?0:u+1;
		if (dis[v]>dis[u]+1) dis[v]=dis[u]+1,q.pb(v);
	}printf("%d",dis[0]+1);return 0;
}