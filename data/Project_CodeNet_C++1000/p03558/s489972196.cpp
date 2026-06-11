#include <queue>
#include <stdio.h>
#include <string.h>
#define R register
#define MN 100005
std::deque<int> q;
int k,dis[MN];bool vis[MN];
int main(){
	scanf("%d",&k);
	memset(dis,0x3f,sizeof(dis));
	dis[1]=0;q.push_back(1);
	while(!q.empty()){
		R int x=q.front();q.pop_front();
		if (vis[x]) continue;
		if (!x) break;vis[x]=1;
		if (dis[x*10%k]>dis[x]){
			dis[x*10%k]=dis[x];
			q.push_front(x*10%k);
		}
		if (dis[x+1==k?0:x+1]>dis[x]+1){
			q.push_back(x+1==k?0:x+1);
			dis[x+1==k?0:x+1]=dis[x]+1;
		}
	}printf("%d\n",dis[0]+1);return 0;
}