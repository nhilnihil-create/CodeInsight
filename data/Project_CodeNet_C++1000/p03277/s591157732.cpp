#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn],b[maxn],c[maxn],d[maxn],pre[maxn],n,tot;

inline void add(int x,int val){for(int i=x;i<=maxn-4;i+=i&-i) c[i]+=val;}
inline ll q(int x){ll res=0; for(int i=x;i;i-=i&-i) res+=c[i]; return res;}

inline bool jud(ll x)
{
	ll tmp=0,cnt=0;
	for(int i=1;i<=n;i++) if(a[i]<x) b[i]=-1; else b[i]=1;
	for(int i=0;i<=maxn-4;i++) c[i]=0; add(1e5,1);
	for(int i=1;i<=n;i++) pre[i]=pre[i-1]+b[i],tmp+=q(pre[i]+1e5),add(pre[i]+1e5,1);
	if(tmp+cnt>=tot/2) return true; return false;
}

int main()
{
	n=read(); tot=n*(n+1)/2;
	for(int i=1;i<=n;i++) a[i]=read(),d[i]=a[i]; sort(d+1,d+n+1);
	int l=1,r=n,ans=0;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(jud(d[mid])) ans=d[mid],l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}