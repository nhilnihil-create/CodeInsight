#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

map <ll,int> p;
ll a[maxn],n,ans;

int main()
{
	n=read(); rep(i,1,n) a[i]=read(),p[a[i]]++; sort(a+1,a+n+1);
	per(i,n,1)
	{
		if(!p[a[i]]) continue;
		for(int x=31;x>=0;x--)
		{
			ll tmp=1ll<<x; tmp-=a[i]; if(tmp<=0) break;
			if(tmp==a[i]&&p[tmp]>=2) p[tmp]-=2,ans++;
			else if(tmp!=a[i]&&p[tmp]) p[tmp]--,p[a[i]]--,ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
