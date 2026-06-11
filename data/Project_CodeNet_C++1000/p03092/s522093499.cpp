#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<cmath>
#include<stack>
#include<algorithm>
#define rg register
#define ll long long
#define LDB long double
#define ull unsigned long long
#define view(i,x) for(rg int i=hd[x];i!=-1;i=e[i].nt)
#define go(i,x,a) for(rg int i=a;i<x;i++)
#define inf 0x3f3f3f3f
#define INF 0x7fffffff
using namespace std;

const int maxn=5e3+5;
int n,a[maxn];
ll A,B,f[maxn][maxn],sf[maxn][maxn];

inline int rd(){
	int ret=0,af=1; char gc=getchar();
	while(gc < '0' || gc > '9'){ if(gc=='-') af=-af; gc=getchar(); }
	while(gc >= '0' && gc <= '9') ret=ret*10+gc-'0',gc=getchar();
	return ret*af;
}

inline void gmin(ll &a,ll b){
	if(a > b) a=b; return ;
}

int main(){
	#ifndef ONLINE_JUDGE
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	#endif
	n=rd(); A=rd(); B=rd(); int x;
	go(i,n+1,1) x=rd(),a[x]=i;
	memset(sf,7,sizeof(sf)); memset(f,7,sizeof(f));
	go(i,n+1,1) sf[0][i]=0;
	go(i,n+1,1){
		go(j,n+1,1){
			if(j < a[i]) gmin(f[i][j],sf[i-1][j]+B);
			if(j == a[i]) gmin(f[i][j],sf[i-1][j]);
			if(j > a[i]) gmin(f[i][j],sf[i-1][j]+A);
			sf[i][j]=sf[i][j-1];
			gmin(sf[i][j],f[i][j]);
		}
	}
	ll ans=1e18;
	go(i,n+1,1) gmin(ans,f[n][i]);
	printf("%lld",ans);
	return 0;
}//Faze
