#include<bits/stdc++.h>
#define reg register
typedef long long ll;
using namespace std;
const int MN=1<<18;
int n,a[MN],lim,x[MN],y[MN];
inline void calc(int v,int pos){
	if(x[pos]==v||y[pos]==v)return;
	if(a[x[pos]]<a[v])y[pos]=x[pos],x[pos]=v;
	else if(a[y[pos]]<a[v])y[pos]=v;
}
int main(){
	scanf("%d",&n);lim=1<<n;
	for(reg int i=0;i<lim;i++)scanf("%d",a+i),x[i]=i,y[i]=lim;
	for(reg int i=0;i<lim;i++)
		for(reg int j=0;j<n;j++)
			if(i&(1<<j)){
				reg int k=i^(1<<j);
				calc(x[k],i),calc(y[k],i);
			}
	for(reg int i=1,ans=0;i<lim;i++)printf("%d\n",ans=max(ans,a[x[i]]+a[y[i]]));
	return 0;
}