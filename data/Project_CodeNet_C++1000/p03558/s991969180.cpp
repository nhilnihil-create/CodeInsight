#include <queue>
#include <cstdio>
#include <cstring>
using namespace std;
#define Maxn 100000
int k;
int dis[Maxn+5];
bool in[Maxn+5];
void spfa(){
	memset(dis,0x3f,sizeof dis);
	dis[1]=1;
	queue<int> q;
	q.push(1);
	in[1]=1;
	int u,v;
	while(!q.empty()){
		u=q.front();
		in[u]=0;
		q.pop();
		v=(u+1)%k;
		if(dis[u]+1<dis[v]){
			dis[v]=dis[u]+1;
//			printf("%d-->%d 1 %d %d\n\n",u,v,dis[u],dis[v]);
			if(!in[v]){
				q.push(v);
				in[v]=1;
			}
		}
		v=(u*10)%k;
		if(dis[u]<dis[v]){
			dis[v]=dis[u];
//			printf("%d-->%d 0 %d %d\n",u,v,dis[u],dis[v]);
			if(!in[v]){
				q.push(v);
				in[v]=1;
			}
		}
	}
}
int main(){
	scanf("%d",&k);
	spfa();
	printf("%d\n",dis[0]);
	return 0;
}
