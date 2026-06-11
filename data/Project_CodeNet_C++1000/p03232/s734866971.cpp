#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL p=1e9+7;
const LL N=1e5+10;
inline LL pw(LL x,LL y){
	LL ans=1; while(y){
		if(y&1)(ans*=x)%=p;
		x=x*x%p; y>>=1;
	}
	return ans;
}
LL n,a[N];
LL s[N];
int main(){
	scanf("%lld",&n);
	for(LL i=1; i<=n; ++i)scanf("%lld",&a[i]);
	for(LL i=1; i<=n; ++i)s[i]=(pw(i,p-2)+s[i-1])%p;
	LL ans=0;
	for(LL i=1; i<=n; ++i)
		(ans+=(s[i]+s[n-i+1]-1)*a[i]%p)%=p;
	for(LL i=1; i<=n; ++i)(ans*=i)%=p;
	printf("%lld",ans);
	return 0;
}