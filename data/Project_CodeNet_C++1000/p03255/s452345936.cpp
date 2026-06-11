#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;
const int N=200010;
const LL inf=18446744073709551615ull;
int n,X,a[N];
LL f[N];
int main(){
	scanf("%d%d",&n,&X);
	for(int i=1; i<=n; ++i)scanf("%d",&a[i]),f[i]=f[i-1]+a[i];
	LL mn=inf;
	for(int i=1; i<=n; ++i){
		LL ans=(f[n]-f[n-i])*2;
		for(int j=n,k=3; j>=1; j-=i,k+=2)
			ans+=1ll*(f[j]-f[max(j-i,0)])*k;
		mn=min(mn,ans+1ll*(i+n)*X);
	}
	printf("%lld",mn);
	return 0;
}