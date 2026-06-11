#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename TYPE> inline void chkmax(TYPE &x,TYPE y){x<y?x=y:0;}
template <typename TYPE> inline void chkmin(TYPE &x,TYPE y){y<x?x=y:0;}
template <typename TYPE> void readint(TYPE &x)
{
    x=0;int f=1;char c;
    for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}
const int MAXN=200005,INF=0x3f3f3f3f;

int n,a[MAXN];
int lazy[MAXN<<2|1];
void pushdown(int id)
{
	if(lazy[id]==INF)return;
	lazy[id<<1]=lazy[id<<1|1]=lazy[id];
	lazy[id]=INF;
}
void modify(int id,int l,int r,int ql,int qr,int c)
{
	if(l==ql && r==qr){lazy[id]=c;return;}
	pushdown(id);
	int mid=(l+r)>>1;
	if(qr<=mid)modify(id<<1,l,mid,ql,qr,c);
	else if(ql>mid)modify(id<<1|1,mid+1,r,ql,qr,c);
	else modify(id<<1,l,mid,ql,mid,c),modify(id<<1|1,mid+1,r,mid+1,qr,c);
}
int query(int id,int l,int r,int x)
{
	if(l==r)return lazy[id]+x;
	pushdown(id);
	int mid=(l+r)>>1;
	if(x<=mid)return query(id<<1,l,mid,x);
	return query(id<<1|1,mid+1,r,x);
}

int main()
{
	#ifndef ONLINE_JUDGE
//	freopen("code.in","r",stdin);
//	freopen("code.out","w",stdout);
	#endif
	readint(n);
	for(int i=1;i<=n;++i)readint(a[i]);
	if(a[1])return 0*printf("-1\n");
	for(int i=2;i<=n;++i)
		if(a[i]>a[i-1]+1)return 0*printf("-1\n");
	memset(lazy,0x3f,sizeof(lazy));
	for(int i=1;i<=n;++i)modify(1,1,n,i,i,-i);
	ll ans=0;
	for(int i=n;i>1;--i)
	{
		int t=query(1,1,n,i);
		if(a[i]==t)continue;
		ans+=a[i];
		modify(1,1,n,i-a[i]+1,i,a[i]-i);
	}
	printf("%lld\n",ans);
	return 0;
}