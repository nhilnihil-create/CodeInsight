#include<bits/stdc++.h>
#define N 100005
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
int n,cnt,h[N],col[N];
struct Edge{
	int to,next,w;
}a[N*2];
void Add(int x,int y){
	int z=read();
	cnt++;a[cnt].to=y;a[cnt].next=h[x];a[cnt].w=z;h[x]=cnt;
	cnt++;a[cnt].to=x;a[cnt].next=h[y];a[cnt].w=z;h[y]=cnt;
}
void dfs(int x,int fa){
	for(int i=h[x];i;i=a[i].next){
		int y=a[i].to;
		if(y==fa)continue;
		if(a[i].w&1)col[y]=col[x]^1;
		else col[y]=col[x];
		dfs(y,x);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;i++)Add(read(),read());
	col[1]=2;
	dfs(1,0);
	for(int i=1;i<=n;i++)printf("%d\n",col[i]-2);
}