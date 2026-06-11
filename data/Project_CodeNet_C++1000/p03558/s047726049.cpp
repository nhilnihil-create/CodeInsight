#include<bits/stdc++.h>
using namespace std;
#define RI register int
const int N=100005,inf=0x3f3f3f3f;
int n,tot,dis[N],h[N],ne[N<<1],to[N<<1],w[N<<1];
deque<int> q;
void add(int x,int y,int z) {to[++tot]=y,ne[tot]=h[x],h[x]=tot,w[tot]=z;}
void bfs() {
	for(RI i=0;i<n;++i) dis[i]=inf;
	dis[1%n]=1,q.push_back(1%n);
	while(!q.empty()) {
		int x=q.front();q.pop_front();
		for(RI i=h[x];i;i=ne[i])
			if(dis[x]+w[i]<dis[to[i]]) {
				dis[to[i]]=dis[x]+w[i];
				if(!w[i]) q.push_front(to[i]);
				else q.push_back(to[i]);
			}
	}
}
int main()
{
	scanf("%d",&n);
	for(RI i=0;i<n;++i) add(i,(i+1)%n,1),add(i,i*10%n,0);
	bfs(),printf("%d\n",dis[0]);
	return 0;
}