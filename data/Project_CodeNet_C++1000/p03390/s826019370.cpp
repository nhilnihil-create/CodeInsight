#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 1e9
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

inline ll sqr(ll x)
{
	ll l=0,r=1e9,ans=0;
	while(l<=r)
	{
		ll mid=(l+r)>>1;
		if(mid*mid<=x) l=mid+1,ans=mid;
		else r=mid-1;
	}
	return ans;
}

int main()
{
	int Q=read();
	while(Q--)
	{
		ll a=read(),b=read(),ans; if(a>b) swap(a,b);
		if(a==1&&b==1) {puts("0"); continue;}
		ll tmp=(ll)sqr(a*b-1),p=sqrt(a*b-1); ans=tmp*2;
		if((ll)((a*b-1)/p)==p) ans--;
		if(a!=b) ans--; printf("%lld\n",max(ans,0ll));
	}
	return 0;
}