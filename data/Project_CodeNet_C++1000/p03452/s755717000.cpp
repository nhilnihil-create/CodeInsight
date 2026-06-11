#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,f[N],d[N];
bool flag=1;
int find(int x){
	if(x==f[x])return x;
	int tmp=find(f[x]);
	d[x]+=d[f[x]];
	return f[x]=tmp;
}
bool work(int x,int y,int z){
	int rx=find(x),ry=find(y);
	if(rx==ry){
		if(d[y]-d[x]==z)return 1;
		else return 0;
	}
	f[ry]=rx;
	d[ry]=d[x]+z-d[y];
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m;i++){
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		if(flag)flag=work(x,y,z); 
	}
	if(flag)puts("Yes");
	else puts("No"); 
	return 0;
}