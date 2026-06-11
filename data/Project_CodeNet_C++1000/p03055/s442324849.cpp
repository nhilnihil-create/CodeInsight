#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,x,y,ne[N],fi[N],zz[N],ans,tot,Maxsd[N],sd[N];
void jb(int x,int y){
	ne[++tot]=fi[x];
	fi[x]=tot;
	zz[tot]=y;
}
void dfs(int x,int y,int z){
	Maxsd[x]=sd[x]=z;
	for (int i=fi[x];i;i=ne[i])
		if (zz[i]!=y){
			dfs(zz[i],x,z+1);
			ans=max(ans,Maxsd[x]+Maxsd[zz[i]]-2*sd[x]);
			Maxsd[x]=max(Maxsd[x],Maxsd[zz[i]]);
		}
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		jb(x,y);jb(y,x);
	}
	dfs(1,0,0);
	if (ans%3==1)puts("Second");
	else puts("First");
}