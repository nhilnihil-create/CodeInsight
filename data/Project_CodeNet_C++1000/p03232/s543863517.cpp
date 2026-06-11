#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=1e5+10,mod=1e9+7;
int n;
ll ans,inv[maxn];

int main(){
	inv[1]=1;
	for(int i=2;i<maxn;++i)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<maxn;++i)
		inv[i]=(inv[i-1]+inv[i])%mod;
	cin>>n;
	for(int i=1,a;i<=n;++i){
		cin>>a;
		(ans+=a*(inv[i]+inv[n-i+1]-inv[1]+mod))%=mod;
	}
	for(int i=1;i<=n;++i)
		ans=ans*i%mod;
	printf("%lld\n",ans);
	return 0;
}