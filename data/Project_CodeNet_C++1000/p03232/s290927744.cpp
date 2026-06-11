#include<bits/stdc++.h>
#define LL long long
using namespace std;

const int N=1e5+50,mod=1e9+7;
int n,A[N];
int fac[N],inv[N];
int cnt[N];

inline int read(){
    int x=0,f=1;char ch=getchar();
    for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=getchar())x=(x<<3)+(x<<1)+ch-'0';
    return x*f;
}
inline void Add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
inline void Sub(int &x,int y){
	x-=y;if(x<0)x+=mod;
}
int Pow(int x,int k){
	if(k==0)return 1;
	int Res=Pow(x,k>>1);Res=1LL*Res*Res%mod;
	if(k&1)Res=1LL*Res*x%mod;
	return Res;
}
void Prework(){
	fac[0]=1;
	for(int i=1;i<=n;++i)fac[i]=1LL*fac[i-1]*i%mod;
	inv[n]=Pow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)inv[i]=1LL*inv[i+1]*(i+1)%mod;
}
void Chafen(){
	for(int i=1;i<=n;++i)Add(cnt[i],cnt[i-1]);
}
int C(int x,int y){
	return 1LL*fac[x]*inv[y]%mod*inv[x-y]%mod;
}

int main(){
	n=read();
	for(int i=1;i<=n;++i)A[i]=read();
	if(n==1)return printf("%d\n",A[1])*0;
	Prework();
	for(int i=1;i<=n-2;++i){
		int qwq=2LL*fac[i]*fac[n-i-2]%mod*C(n,i+2)%mod;
		Add(cnt[2],qwq);Sub(cnt[i+2],qwq);
		Sub(cnt[n-i+1],qwq);
	}
	Chafen();
	for(int i=1;i<n;++i){
		int qwq=1LL*fac[i]*fac[n-i-1]%mod*C(n,i+1)%mod;
		Add(cnt[1],qwq);Sub(cnt[i+1],qwq);
		Add(cnt[n-i+1],qwq);
	}
	Add(cnt[1],fac[n]);
	Chafen();
	int ans=0;
	for(int i=1;i<=n;++i)Add(ans,1LL*cnt[i]*A[i]%mod);
	printf("%d\n",ans);
	return 0;
}