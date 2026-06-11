#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,a,b,k;
long long ans;
long long mul[300005],inv[300005];


long long ksm(long long a,long long x){
	long long ans=1;
	while(x){
		if(x%2==1) ans=ans*a%mod;
		a=a*a%mod;
		x/=2;
	}
	return ans;
}

long long C(long long m,long long n){
	if(m<n) return 0;
	return mul[m]*inv[n]%mod*inv[m-n]%mod;
}

int main(){
	cin>>n>>a>>b>>k;
	
	mul[0]=inv[0]=1;
	for(long long i=1;i<=n;i++) mul[i]=mul[i-1]*i%mod;
	inv[n]=ksm(mul[n],mod-2);
	for(long long i=n-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%mod;
	
	for(long long i=0;i<=n && i*a<=k;i++){
		if((k-i*a)%b==0){
			long long j=(k-i*a)/b;
			ans=(ans+C(n,i)*C(n,j))%mod;
		}
	}
	cout<<ans;
	cout<<endl;
}