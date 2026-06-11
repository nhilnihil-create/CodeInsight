#include<bits/stdc++.h>
using namespace std;
long long mod=998244353;
long long n,a,b,c,k,ans;
long long fac[300005],rev[300005];
long long power(long long x,long long y,long long mod){
	if(y==0){
		return 1;
	}else{
		long long dm=power(x,y/2,mod);
		if(y%2==1){
			return ((dm*dm)%mod*x)%mod;
		}else{
			return (dm*dm)%mod;
		}
	}
}
long long inverse_mod(long long a,long long mod){
	return power(a,mod-2,mod);
}
long long C(int k,int n){
	if(k>n){
		return 0;
	}else{
	    return ((fac[n]*rev[k]%mod)*rev[n-k])%mod;
	}
}
int main(){
	cin>>n>>a>>b>>k;
	fac[0]=1;
	rev[0]=inverse_mod(fac[0],mod);
	for(int i=1;i<=n;i++){
		fac[i]=(fac[i-1]*i)%mod;
		rev[i]=inverse_mod(fac[i],mod)%mod;
	}
	if(k==0){
		cout<<"1";
	}else{
		for(long long x=1;x<=k/a&&x<=n;x++){
			long long tmp=k-a*x;
			if(tmp%b==0){
				long long y=tmp/b;
			    ans=(ans+(C(x,n)%mod)*(C(y,n)%mod)%mod)%mod;
			}
		}
		cout<<ans;
	}
}