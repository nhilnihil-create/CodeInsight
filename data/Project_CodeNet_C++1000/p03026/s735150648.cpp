#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
using namespace std;
const long long MAX=1e9+7;
const int Mod=998244353;
int n,a[10010],b[10010],c[10010],u,v,sum,ans[10010];
int que[10010],l,r,vis[10010],tot;
vector <int> edge[10010];
bool cmp(int x,int y){
	return x>y;
}
void bfs(){
	while(l<=r){
		for(int i=0;i<edge[que[l]].size();i++){
			if(vis[edge[que[l]][i]]==1) continue;
			vis[edge[que[l]][i]]=1;
			tot++;
			ans[edge[que[l]][i]]=c[tot];
			r++;
			que[r]=edge[que[l]][i];
		}
		l++;
	}
	return ;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]);
	sort(c+1,c+n+1,cmp);
	for(int i=2;i<=n;i++)
		sum+=c[i];
	l=1;
	r=1;
	que[r]=1;
	vis[1]=1;
	tot=1;
	ans[1]=c[tot];
	bfs();
	printf("%d\n",sum);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	printf("\n");
	return 0;
}