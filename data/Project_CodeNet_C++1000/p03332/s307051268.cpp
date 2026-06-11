#include<bits/stdc++.h>
using namespace std;

const int maxn=300005,mod=998244353;
long long n,a,b,k;
long long ans=0;
long long numa,numb;
long long fac[maxn],inv[maxn],facinv[maxn];//阶乘,逆元,阶乘的逆元
 
void pre(){
	fac[0]=fac[1]=inv[0]=inv[1]=facinv[0]=facinv[1]=1;
        
    for(long long i=2;i<=maxn-5;i++){
        fac[i]=fac[i-1]*i%mod;
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
        facinv[i]=facinv[i-1]*inv[i]%mod;
    }
}

long long C(long long u,long long v){
	return fac[u]*facinv[u-v]%mod*facinv[v]%mod;
}

int main(){
	pre();
	//for(long long i=1;i<=10;i++)  cout<<fac[i]<<' ';
	ios::sync_with_stdio(0);
	cin>>n>>a>>b>>k;
	
	for(long long i=0;i<=n;i++){
		//cout<<i<<endl;
		numa=i;
		if(a*numa>k)  break;
		if((k-a*numa)%b!=0)  continue;
		numb=(k-a*numa)/b;
		if(numb<0 || numb>n)  continue;
		//cout<<1<<endl;
		ans=(ans+C(n,numa)*C(n,numb)%mod)%mod;
		//cout<<ans<<endl; 
		//cout<<numa<<' '<<numb<<endl;
		//cout<<C(n,numa)<<' '<<C(n,numb)<<endl;
	}
	
	cout<<ans;
	
	return 0;
}