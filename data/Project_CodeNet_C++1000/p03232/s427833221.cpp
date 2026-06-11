#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define foreach(c,itr) for (__typeof((c).begin()) itr=(c).begin();itr!=(c).end();++itr)
using namespace std;
const int mod=1e9+7;
int n,i,j,f[100005],inv[100005],ans;
int main(){
	cin>>n;
	inv[1]=f[1]=1;
	for(i=2;i<=n;i++){
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
		f[i]=(f[i-1]+inv[i])%mod;
	}
	rep(i,n){
		int x;
		cin>>x;
		ans=(ans+1ll*x*(f[i]+f[n-i+1]-1))%mod;
	}
	rep(i,n){
		ans=1ll*ans*i%mod;
	}
	cout<<ans<<endl;
	return 0;
}