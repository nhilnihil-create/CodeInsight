#include<bits/stdc++.h>
using namespace std;
int n,ans,cnt,c[1<<17],d[1<<17];
vector<int>G[1<<17];
void dfs(int now,int prev){
	d[now]=c[++cnt];
	for(auto e:G[now])if(e!=prev)dfs(e,now);
}
int main(){
	scanf("%d",&n);
	for(int i=1,x,y;i<n;i++)scanf("%d%d",&x,&y),G[x].push_back(y),G[y].push_back(x);
	for(int i=1;i<=n;i++)scanf("%d",&c[i]);
	sort(c+1,c+n+1),reverse(c+1,c+n+1);
	for(int i=2;i<=n;i++)ans+=c[i];
	printf("%d\n",ans);
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%d ",d[i]);
}
