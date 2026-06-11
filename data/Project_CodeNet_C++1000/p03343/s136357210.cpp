#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int n,k,Q,a[maxn],p[maxn],c[maxn],d[maxn],c2,q[maxn],c3,ans;

inline void wk(int x)
{
	rep(i,1,n) if(a[i]>=a[x]) p[i]=1; c2=0; c3=0;
	rep(i,1,n)
	{
		int cnt=0;
		while(p[i]==1) cnt++,d[++c2]=a[i],i++;
		sort(d+1,d+c2+1);
		rep(j,1,(c2-k+1)) q[++c3]=d[j]; c2=0;
	}
	sort(q+1,q+c3+1); if(q[Q]) ans=min(ans,q[Q]-a[x]);
	rep(i,1,c3) q[i]=0; rep(i,1,n) p[i]=0;
}

int main()
{
	n=read(); k=read(); Q=read(); rep(i,1,n) a[i]=read(); ans=inf;
	rep(i,1,n) wk(i); cout<<ans<<endl;
	return 0;
}