#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define N 100010
inline int read(){
	char ch=getchar(); int x=0;
	for (;ch>'9'||ch<'0';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}
int n,inv[N],S[N],fac[N],ans;
int pw(int a,int b){int res=1; for (;b;b>>=1,(a*=a)%=M) if (b&1) (res*=a)%=M; return res;}
signed main(){
	n=read();
	inv[1]=1; for (int i=2;i<=n;i++) inv[i]=1LL*inv[M%i]*(M-M/i)%M;
	for (int i=1;i<=n;i++) S[i]=(S[i-1]+inv[i])%M;
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%M;
	for (int i=1;i<=n;i++){
		int x=read();
		(ans+=x*(S[i]+S[n-i+1]-1)%M)%=M;
	}
	(ans*=fac[n])%=M;
	printf("%lld\n",ans);
	return 0;	
}
