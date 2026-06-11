#include<bits/stdc++.h>
const int N=1e3+5;
int n,k,a[N],i,j,xb,z;
long long b[N*N/2],ans,s,x;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i)for(j=i,s=0;j<=n;++j)b[++xb]=s+=a[j];
	for(i=60;i>=0;--i){
		z=0;x=ans|(1ll<<i);
		for(j=1;j<=xb;++j)if((b[j]&x)==x)++z;
		if(z>=k)ans=x;
	}
	printf("%lld\n",ans);
	return 0;
}