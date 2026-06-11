#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
const int MN=2005;
int n,m,q,a[MN],b[MN],c[MN],t[MN],top;
inline void ins(int l,int r){
	reg int tot=0;
	for(reg int i=l;i<=r;i++)t[++tot]=a[i];
	sort(t+1,t+1+tot);
	for(reg int i=1;i<=r-l+2-m;i++)c[++top]=t[i];
}
inline int calc(int x){
	reg int pre=1;top=0;
	for(reg int i=1;i<=n;i++)
		if(a[i]<x)ins(pre,i-1),pre=i+1;
	if(top<q)return 0x3f3f3f3f;
	sort(c+1,c+1+top);
	return c[q]-x;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(reg int i=1;i<=n;i++)
		scanf("%d",a+i),b[i]=a[i];
	sort(b+1,b+1+n);
	reg int N=unique(b+1,b+1+n)-b-1,ans=0x3f3f3f3f;
	a[++n]=-0x3f3f3f3f;
	for(reg int i=1;i<=N;i++)ans=min(ans,calc(b[i]));
	printf("%d\n",ans);
	return 0;
}