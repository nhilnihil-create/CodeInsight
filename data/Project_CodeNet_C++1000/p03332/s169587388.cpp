#include<stdio.h>
long long mod=998244353;
long long fac[1000005];
long long inv(long long b){
	if(b==1)
		return 1;
	return (mod-mod/b)*inv(mod%b)%mod;
}
int main(){
	long long N,A,B;long long K;long long ans=0;
	scanf("%lld%lld%lld%lld",&N,&A,&B,&K);
	fac[0] = 1;
	fac[1] = 1;
	for(int i=2;i <= 3e5+5;i++)
		fac[i] = (fac[i-1]*i)%mod;
	for(int i=0;i<=N;i++){
		if((K-i*A)>=0&&(K-i*A)%B==0&&(K-i*A)/B<=N){
			long long  b=(K-i*A)/B;
			long long tmp1=(fac[N-i]*fac[i])%mod;
			long long tmp2=(fac[N-b]*fac[b])%mod;
			ans=(ans+((fac[N]*inv(tmp1))%mod)*((fac[N]*inv(tmp2))%mod))%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
} 