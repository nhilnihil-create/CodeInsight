#include<bits/stdc++.h>
#define N 1000005
using namespace std;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<3)+(x<<1)+c-'0';c=getchar();}
	return x*f;
}
int n,m,prt[N];
int find(int x){return x==prt[x]?x:prt[x]=find(prt[x]);}
void Merge(int x,int y){
	x=find(x),y=find(y);
	if(x==y)return;
	prt[x]=y;
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n*3;i++)prt[i]=i;
	for(int i=1;i<=m;i++){
		int x=read(),y=read(),z=read();
		Merge(x+2*n,y+2*n);
//		if(z&1)Merge(x,y+n),Merge(x+n,y);
//		else Merge(x+n,y+n),Merge(x,y);
	}
	int ans=0;
	for(int i=n*2+1;i<=n*3;i++)ans+=(prt[i]==i);
	printf("%d\n",ans);
}