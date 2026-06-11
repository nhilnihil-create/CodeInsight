#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 2e18
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,x,a[maxn],pre[maxn];

int main()
{
	n=read(); x=read(); rep(i,1,n) a[i]=read(),pre[i]=pre[i-1]+a[i];
	ll ans=inf;
	for(ll k=1;k<=n;k++)
	{
		ll nw=3,tmp=0;
		for(ll i=n;i>=1;i-=k)
		{
			tmp+=max(nw,5ll)*(pre[i]-pre[max(0ll,i-k)]); nw+=2;
			if(tmp>ans) break;
		}
		ans=min(ans,tmp+(k+n)*x);
	}
	cout<<ans<<endl;
	return 0;
}