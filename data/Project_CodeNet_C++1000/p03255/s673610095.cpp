#include<bits/stdc++.h>
typedef long long ll;
const int N=2e5+5;
int n,X,x[N],i,j;
ll ans=1ll<<60,su[N];
int main(){
	scanf("%d%d",&n,&X);
	for(i=1;i<=n;++i)scanf("%d",x+i),su[i]=su[i-1]+x[i];
	for(i=1;i<=n;++i){
		ll z=1ll*i*X+5*(su[n]-su[n-i]);
		for(j=2;n>(j-1)*i && z<ans;++j)z+=(j<<1|1)*(su[n-(j-1)*i]-su[std::max(0,n-j*i)]);
		ans=std::min(ans,z);
	}
	printf("%lld\n",ans+1ll*n*X);
	return 0;
}
