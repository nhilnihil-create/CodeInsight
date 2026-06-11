#include<cstdio>
#include<cstring>
#include<iomanip>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include<bitset>
#include<stack>
#include<cassert>
#define F first
#define S second
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define mem(x,y) memset(x,y,sizeof x)
#define sqr(x) ((x)*(x))
using namespace std;
typedef long long ll;
typedef double db;
const int INF=2e9;
const db eps=1e-12;
template<typename T>
inline void read(T &x) {
	x=0; int f=1; char ch=getchar();
	while( (ch<'0' || ch>'9') && ch!='-') ch=getchar(); if(ch=='-') {f=-1; ch=getchar();}
	while(ch>='0' && ch <='9') x=x*10+ch-'0',ch=getchar();
	x*=f;
}
//==========================head template==========================
const int N=100010;
int a[N],n,L=INF,R=-INF;
int seq[N];
inline int lowbit(int x) {return x&(-x);}
int c[N<<2];
inline void Add(int u,int v) {
	while(u<=2*n+1) {
		c[u]+=v;
		u+=lowbit(u);
	}
}
inline ll Query(int u) {
	ll ret=0;
	while(u) {
		ret+=1ll*c[u];
		u-=lowbit(u);
	}
	return ret;
}
inline bool Judge(int x) {
	for(int i=1;i<=n;i++) seq[i]=(a[i]<x ? -1 : 1);
	mem(c,0); seq[0]=n+1;
	for(int i=1;i<=n;i++)
		seq[i]+=seq[i-1];
	ll ans=0;
	Add(n+1,1);
	// for(int i=1;i<=n;i++) printf("%d ",seq[i]); puts("");
	for(int i=1;i<=n;i++) {
		ans+=Query(seq[i]);
		Add(seq[i],1);
		// printf("%lld\n",ans);
	}
	return ans>=1ll*n*(n+1)/2/2;
}
signed main() {
	read(n);
	for(int i=1;i<=n;i++) {
		read(a[i]);
		R=max(R,a[i]);
		L=min(L,a[i]);
	}
	// Judge(30);
	int ret=0;
	while(L<=R) {
		int mid=(L+R)>>1;
		if(Judge(mid)) {L=mid+1; ret=mid;}
		else R=mid-1;
	}
	printf("%d\n",ret);
	return 0;
}
/*
3
10 30 20
*/