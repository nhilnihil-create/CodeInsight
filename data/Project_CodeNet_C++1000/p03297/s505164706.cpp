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

int main()
{
	int T=read();
	while(T--)
	{
		ll a=read(),b=read(),c=read(),d=read(); ll tmp=__gcd(b,d);
		if(a<b||d<b) {puts("No"); continue;}
		d%=b; a%=tmp; a-=tmp; a+=b;
		if(a>c) puts("No"); else puts("Yes");
		//cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	}
	return 0;
}