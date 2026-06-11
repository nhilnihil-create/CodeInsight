#include <stdio.h>
#include <string.h>
#include <queue>
#define N 100010
int n,d[N];char inq[N];
inline int spfa(int s,int t) {
	std::queue<int> q;int u,v;
	memset(d,33,sizeof(d));
	q.push(s);d[s]=0;inq[s]=1;
	while(!q.empty()) {
		u=q.front();q.pop();inq[u]=0;
		v=u*10%n;
		if(d[u]<d[v]) {
			d[v]=d[u];
			if(!inq[v]) q.push(v),inq[v]=1;
		}
		v=u+1;if(v==n) v=0;
		if(d[u]+1<d[v]) {
			d[v]=d[u]+1;
			if(!inq[v]) q.push(v),inq[v]=1;
		}
	}
	return d[t];
}
int main() {
	scanf("%d",&n);
	printf("%d\n",1+spfa(1,0));
	return 0;
}