#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
int k,cnt=0,h[100005],dis[100005];
struct Edge{
	int to,next,w;
}e[400005];
queue<int> q;
inline void add(int u,int v,int w){
	e[++cnt].to=v;
	e[cnt].next=h[u];
	e[cnt].w=w;
	h[u]=cnt;
}
inline void init(){
	scanf("%d",&k);
	for(int i=0;i<k-1;i++){
		add(i,i*10%k,0);
		add(i,i+1,1);
	}
	add(k-1,(k-1)*10%k,0);
	add(k-1,0,1);
	memset(dis,127/3,sizeof(dis));
	dis[1]=0;
}
int main(){
	init();
	q.push(1);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=h[x];i;i=e[i].next)
			if(dis[e[i].to]>dis[x]+e[i].w){
				dis[e[i].to]=dis[x]+e[i].w;
				q.push(e[i].to);
			}
	}
	printf("%d\n",dis[0]+1);
	return 0;
}