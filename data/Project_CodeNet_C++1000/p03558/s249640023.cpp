#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
#define MN 100005
int n;
int q[MN*2],p[MN*2];
int l,r;
bool vis[MN];
int main(){
	n=read();
	q[l=r=MN]=1;p[MN]=1;
	while(l<=r){
		int Q=q[l],P=p[l++];
		if(vis[Q]) continue;vis[Q]=1;
		if(Q==0){printf("%d\n",P);return 0;}
	//	if(!vis[(Q*10)%n]){
	//		vis[(Q*10)%n]=true;
			q[--l]=(Q*10)%n;
			p[l]=P;
	//	}
	//	if(!vis[(Q+1)%n]){
	//		vis[(Q+1)%n]=true;
			q[++r]=(Q+1)%n;
			p[r]=P+1;
	//	}
	}
	return 0;
}