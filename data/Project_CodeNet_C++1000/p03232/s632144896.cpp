/* --- author: dxm --- */
#include<bits/stdc++.h>
#pragma GCC optimize(2)
using namespace std;

#define INF 1e9
#define Inf 1e18
#define rep(i,n) for(int (i)=0;(i)<n;i++)
#define REP(i,n) for(int (i)=1;(i)<=n;i++)
#define mp make_pair
#define pb push_back
#define fst first
#define snd second
typedef long long ll;
typedef double db;
typedef long double ldb;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;

void qread(int &x){
	int neg=1;x=0;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')neg=-1;c=getchar();}
	while(c>='0'&&c<='9')x=10*x+c-'0',c=getchar();
	x*=neg;
}

const int mod=1e9+7;
int Add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
int Sub(int a,int b){return a-b<0?a-b+mod:a-b;}
int Mul(int a,int b){return 1LL*a*b%mod;}

const int maxn=100005;
int n;
int a[maxn],sum[maxn],fac[maxn],inv[maxn];

int quickpow(int x,int pow){
	int res=1;
	for(;pow;pow>>=1){
		if(pow&1)res=Mul(res,x);
		x=Mul(x,x);
	}
	return res;
}

int C(int a,int b){
	return Mul(fac[a],Mul(inv[b],inv[a-b]));
}

int main(){
#ifdef FILE
	freopen("FILE.in","r",stdin);
	freopen("FILE.out","w",stdout);
#endif
	scanf("%d",&n);
	fac[0]=inv[0]=1;
	REP(i,n){
		fac[i]=Mul(fac[i-1],i);
		inv[i]=quickpow(fac[i],mod-2);
	}
	REP(i,n){
		scanf("%d",&a[i]);
		sum[i]=Add(sum[i-1],a[i]);
	}
	int ans=Mul(fac[n],sum[n]);
	for(int i=2;i<=n;i++){
		int coef=Mul(C(n,i),Mul(fac[n-i],fac[i-1]));
		ans=Add(ans,Mul(coef,sum[n-i+1]));
		ans=Add(ans,Mul(coef,Sub(sum[n],sum[i-1])));
	} 
	printf("%d\n",ans);
#ifdef TIME
	printf("Running Time = %d ms\n",int(clock()*1000.0/CLOCKS_PER_SEC));
#endif
	return 0;
}

/*
Input:
-----------------
Output:
*/
