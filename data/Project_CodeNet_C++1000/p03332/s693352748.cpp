#include<bits/stdc++.h>
using namespace std;

#define INF int(1e9)
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef pair<int,int> pii;

const int maxn=300005;
const int mod=998244353;
int n,ans;
ll A,B,K;
int fac[maxn],ifac[maxn];

ll gcd(ll a,ll b){
	return !b?a:gcd(b,a%b);
}
int C(int a,int b){
	if(a<b||a<0||b<0)return 0;
	return 1LL*fac[a]*ifac[b]%mod*ifac[a-b]%mod;
}

int main(){
	scanf("%d%lld%lld%lld",&n,&A,&B,&K);
	fac[0]=fac[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<=n;i++){
		fac[i]=1LL*fac[i-1]*i%mod;
		ifac[i]=1LL*ifac[mod%i]*(mod-mod/i)%mod;
	}
	REP(i,n)ifac[i]=1LL*ifac[i-1]*ifac[i]%mod;
	ll d=gcd(A,B);
	if(K%d){
		puts("0");
		return 0;
	}
	A/=d;B/=d;K/=d;
	rep(i,n+1){
		if(K-A*i<0||(K-A*i)%B||(K-A*i)/B>n)continue;
		int j=(K-A*i)/B;
		ans+=1LL*C(n,i)*C(n,j)%mod;
		if(ans>=mod)ans-=mod;
	}
	printf("%d\n",ans);
	return 0;
}