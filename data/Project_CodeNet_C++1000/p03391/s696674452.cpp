#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 2000005
#define inf 1e18
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

ll n,a[maxn],b[maxn],tot,mn;

int main()
{
	n=read(); rep(i,1,n) a[i]=read(),b[i]=read(),tot+=a[i]; mn=inf;
	rep(i,1,n) if(a[i]>b[i]) mn=min(mn,b[i]);
	if(mn==inf) return puts("0"),0;
	printf("%lld\n",tot-mn);
	return 0;
}