#include<iostream>
#define maxm 200010
#define maxn 200010
using namespace std;
int link[maxm],head[maxn],to[maxm],d[maxn];
int tot,flag,ans;
void add(int u,int v){
	link[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
}
void dfs(int x){
	if(flag) return ;
	for(int i=head[x];i;i=link[i]){
		if(d[to[i]]==d[x]) flag=1;
		if(d[to[i]]) continue;
		if(flag) break;
		else{
			if(d[x]==1){
				d[to[i]]=2;
				ans++;
			}
			else d[to[i]]=1;
			dfs(to[i]);
		}
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		add(u,v);
		add(v,u);
	}
	d[1]=1;
	dfs(1);
	if(flag) cout<<1LL*n*(n-1)/2-m<<endl;
	else cout<<1LL*ans*(n-ans)-m<<endl;
	return 0;
}