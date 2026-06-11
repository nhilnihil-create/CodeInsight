#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

#define LL long long
#define fgx cerr<<"--------------"<<endl;
#define dgx cerr<<"=============="<<endl;

inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
const int MAXN = 100010;
const int INF = 2147483600;
const LL Mod = 1000000007LL;

int N; LL a[MAXN+1]; 
LL fac[MAXN+1],f[MAXN+1],ifac[MAXN+1],inv[MAXN+1];

inline LL C(LL n,LL m){
	return fac[n]*ifac[m]%Mod*ifac[n-m]%Mod;
}

int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	N=read(); for(int i=1;i<=N;i++) a[i]=read(); fac[0]=1; ifac[0]=1; inv[1]=1;
	for(int i=2;i<=N;i++) inv[i]=(Mod-(Mod/i)*inv[Mod%i]%Mod)%Mod;
	for(int i=1;i<=N;i++){
		fac[i]=fac[i-1]*i%Mod; ifac[i]=ifac[i-1]*inv[i]%Mod;
		f[i]=(f[i-1]*i%Mod+f[i-1]+fac[i])%Mod;
	} LL ans=0;
	for(int i=1;i<=N;i++){
		int d=(f[i-1]*fac[N-i]%Mod*C(N,i)%Mod+f[N-i]*fac[i-1]%Mod*C(N,N-i+1)%Mod)%Mod;
		(ans+=d*a[i]%Mod+fac[N]*a[i]%Mod)%=Mod;
	} printf("%lld\n",ans);
	return 0;
}


