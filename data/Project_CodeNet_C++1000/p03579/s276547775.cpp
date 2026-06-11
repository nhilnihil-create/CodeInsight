#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,col[100005],flag=0,cnt,hd[100005],ans1=0,ans2=0;
struct node{
	int to,next;
}e[200005];
void addedge(int x,int y){
	e[++cnt].next=hd[x];
	e[cnt].to=y;
	hd[x]=cnt;
}
void dfs(int x,int fa,int color){
	col[x]=color;
	for(int i=hd[x];i;i=e[i].next){
		int to=e[i].to;
		if(to==fa) continue;
		if(col[to]&&color==col[to]) flag=1; 
		if(!col[to]) dfs(to,x,3-color);
	}
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		addedge(a,b);
		addedge(b,a);
	}
	for(int i=1;i<=n;i++) if(!col[i]) dfs(i,0,1);
	if(flag){
		cout<<n*(n-1)/2-m<<endl;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			if(col[i]==1) ans1++;
			else if(col[i]==2) ans2++;
		}
		cout<<ans1*ans2-m<<endl;
	}
	return 0;
}
