#include<cstdio>
#include<cstring>
using namespace std;
#define int long long
int k,head[5002000],tot,dis[5000020],dl[5000020];
bool vis[5000200];
struct node{
	int t,nxt,w;
}e[5000020];
void add(int u,int v,int dis){
	e[++tot].t=v;
	e[tot].w=dis;
	e[tot].nxt=head[u];
	head[u]=tot;
}
void spfa(){
    int head1=1,tail=1;
    memset(dis,127/3,sizeof(dis));
    dl[1]=1;//模拟队列
    vis[1]=1;dis[1]=0;
    for(int v=1;head1<=tail;vis[v]=0,v=dl[++head1])//另类写法
        for(int p=head[v];p;p=e[p].nxt)
            if(dis[e[p].t]>dis[v]+e[p].w){
                dis[e[p].t]=dis[v]+e[p].w;
                if(!vis[e[p].t]) vis[e[p].t]=1,dl[++tail]=e[p].t;
            }
}
signed main(){
	scanf("%lld",&k);
	for(int i=1;i<k;i++){
		add(i,i*10%k,0);
		add(i,(i+1)%k,1);
	}
	spfa();
	printf("%lld",dis[0]+1);
	return 0;
}
