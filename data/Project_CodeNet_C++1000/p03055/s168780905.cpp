#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZEN = 200100;
struct Link{
	int to,next;
}link[SIZEN<<2];
int head[SIZEN],tot = 0;
void add(int from,int to){link[++tot].to = to;link[tot].next = head[from];head[from] = tot;}
int N;
int dis[SIZEN] = {0},root = 1;
int F[SIZEN] = {0};
void DFS(int x,int fa){
	for(int i = head[x];i;i=link[i].next){
		if(link[i].to == fa)continue;
		dis[link[i].to] = dis[x] + 1;
		DFS(link[i].to,x);
	}
	if(dis[root] < dis[x])root = x;
}

int main(){
	scanf("%d",&N);
	for(int i = 1;i < N;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
		add(b,a);
	}
	DFS(root,0);
	memset(dis,0,sizeof dis);
	DFS(root,0);
	int len = 0;
	for(int i = 1;i <= N;i++)len = max(len,dis[i]);
	F[1] = 1;F[2] = 0;
	for(int i = 3;i <= len + 1;i++)F[i] = F[i-1] ^ F[i-2];
//	printf("%d\n",len+1);
	if(F[len + 1])printf("First");
	else printf("Second");
	return 0; 
}