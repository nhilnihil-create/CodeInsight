#include<bits/stdc++.h>
const int MN=200000+5;
using namespace std;
typedef long long ll;
template<typename T>inline T&IN(T&in){
	in=0;char c=getchar();int f=1;
	while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c))in=in*10+c-'0',c=getchar();
	return in*=f;
}
int n;ll ans=1;
int nxt[MN],to[MN],h[MN],cnt,w[MN];
int dis[MN];
queue<int>q;
void add(int u,int v,int _w){to[cnt]=v,nxt[cnt]=h[u],w[cnt]=_w,h[u]=cnt++;}
void input(){
	IN(n);memset(h,-1,sizeof h);memset(dis,63,sizeof dis);
	for(int i=1;i<=n;++i)
		add(i,(i+1)%n,1),add(i,i*10%n,0);
	q.push(1);dis[1]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int e=h[u],v=to[e];~e;e=nxt[e],v=to[e])if(dis[v]>dis[u]+w[e]){
			dis[v]=dis[u]+w[e];
			q.push(v);
		}
	}
	printf("%d\n",dis[0]+1);
}
int main(){
	input();
	return 0;
}