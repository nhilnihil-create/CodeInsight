#include<bits/stdc++.h>
using namespace std;
template<class T>inline void init(T&x){
	x=0;char ch=getchar();bool t=0;
	for(;ch>'9'||ch<'0';ch=getchar()) if(ch=='-') t=1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+(ch-48);
	if(t) x=-x;return;
}
const int N=2e6+10,mod=1e9+7;
typedef long long ll;
int A[N];
template<class T>inline int fpow(int x,T k){int ret=1;for(;k;k>>=1,x=(ll)x*x%mod)if(k&1) ret=(ll)ret*x%mod;return ret;}
template<class T>inline void Inc(T&x,int y){x+=y;if(x>=mod) x-=mod;}
template<class T>inline void Dec(T&x,int y){x-=y;if(x < 0 ) x+=mod;}
int n,f[N],inv[N];
int main()
{
	init(n);f[0]=0;f[1]=1,inv[1]=1;
	init(A[1]);int S=1;
	int fac=1;
	for(int i=2;i<=n;++i) {
		init(A[i]);inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
		f[i]=((ll)S*inv[i]+1)%mod;Inc(S,f[i]);
		fac=(ll)fac*i%mod;
	}
	int ans=0;
	for(int i=1;i<=n;++i) Inc(ans,(ll)(f[i]+f[n-i+1]-1)*A[i]%mod);
	printf("%lld\n" ,(ll)ans*fac%mod);
	//printf("%d\n",ans);
}
