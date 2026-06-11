#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
int n=read();
struct edge{
	int u,v,w;
};
vector<edge> g[100005];
int dist[100005];
inline void dijkstra(){
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
	memset(dist,63,sizeof(dist));
	dist[1]=1;
	pq.push({1,1});
	while(!pq.empty()){
		pair<int,int> p=pq.top();
		pq.pop();
		int s=p.first,x=p.second;
		if(s>dist[x])	continue;
		for(int i=0;i<g[x].size();i++){
			int y=g[x][i].v,z=g[x][i].w;
			if(dist[y]>dist[x]+z){
				dist[y]=dist[x]+z;
				pq.push({dist[y],y});
			}
		}
	}
}
int main(){
	fz(i,0,n-1){
		if(i!=0)	g[i].push_back({i,i*10%n,0});
		g[i].push_back({i,(i+1)%n,1});
	}
	dijkstra();
	print(dist[0]);
	return 0;
}