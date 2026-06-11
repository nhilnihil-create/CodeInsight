#include<bits/stdc++.h>
using namespace std;
const int SIZE=5000;
int n,m;
int cnt=0;
int depth[SIZE+2]={0},low[SIZE+2];
struct edge{
	int x,y,nxt;
}edges[SIZE+2];
int sz=0,h[SIZE+2]={0};
void add_edge(int x,int y){
	sz++;
	edges[sz].x=x;
	edges[sz].y=y;
	edges[sz].nxt=h[x];
	h[x]=sz;
	return;
}
void dfs(int p,int x){
	low[x]=depth[x];
	for(int i=h[x];i;i=edges[i].nxt){
		int y=edges[i].y;
		if(y==p) continue;
		if(!depth[y]){
			depth[y]=depth[x]+1;
			dfs(x,y);
		}
		low[x]=min(low[x],low[y]);
	}
	if(low[x]==depth[x]&&x!=1) cnt++;
	return;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		add_edge(x,y);
		add_edge(y,x);
	}
	depth[1]=1;
	dfs(0,1);
	printf("%d\n",cnt);
	return 0;
} 
/*
7 7
1 3
3 4
4 5
4 6
5 6
6 7
7 2
*/