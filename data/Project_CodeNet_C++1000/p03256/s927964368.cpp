#include<bits/stdc++.h>
#define ll long long
using namespace std;
int tot,n,m,op[500010],e[500010],hd[500010],v[500010],du[500010][2],cnt,nt[500010];
char s[500010];
queue<int>q;
void build(int x,int y){
	tot++;
	e[tot]=y;
	nt[tot]=hd[x];hd[x]=tot;
}
int main(){
	int i,j,x,y;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)op[i]=(s[i]=='A'?0:1);
	for(i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		build(x,y);build(y,x);
		du[x][op[y]]++;du[y][op[x]]++;
	}
	for(i=1;i<=n;i++)if(!du[i][0]||!du[i][1]){
		cnt++;v[i]=1;q.push(i);
	}
	while(!q.empty()){
		x=q.front();q.pop();
		for(i=hd[x];i;i=nt[i])if(!v[e[i]]){
			du[e[i]][op[x]]--;
			if(!du[e[i]][op[x]]){
				cnt++;
				v[e[i]]=1;q.push(e[i]);
			}
		}
	}
	if(cnt==n)puts("No");
	 else puts("Yes");
}