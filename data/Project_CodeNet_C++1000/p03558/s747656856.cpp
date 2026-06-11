#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
#define LL long long
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define Inf 1000000000000000000LL
#define F first
#define S second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,b,a) for(int i=(b);i>=(a);i--)
#define forn(i,n) rep(i,1,n)
#define rep0(i,n) rep(i,0,n-1)
using namespace std;
typedef pair<int,int>pii;
const LL mod=1e9+7;
int head[100010];
int ne;
struct edge{
	int to,nt,w;
}e[500004];
queue<int>q;
int dis[100004];
void dijkstra(){
	memset(dis,127/3,sizeof(dis));
	dis[1]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nt){
			if( dis[e[i].to]>dis[x]+e[i].w){
				dis[e[i].to]=dis[x]+e[i].w;
				q.push(e[i].to);
			}
		}
	}
}
void add(int u,int v,int w){
	 e[++ne].to=v;
	 e[ne].nt=head[u];
	 e[ne].w=w;
	 head[u]=ne;
}
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		add(i,(i+1)%n,1);
		add(i,(i*10)%n,0);
	}
	q.push(1);
	dijkstra();
	cout<<dis[0]+1<<endl;
	return 0;
}
