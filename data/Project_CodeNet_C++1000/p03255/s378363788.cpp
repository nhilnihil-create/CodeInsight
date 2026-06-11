#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
template<typename __T>
inline void read(__T &x)
{
    x=0;
    int f=1;char c=getchar();
    while(!isdigit(c)){if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	{x=x*10+c-'0';c=getchar();}
    x*=f;
}
typedef __int128 ll;
int n;
ll xx;
void out(ll x)
{
	cout<<(long long)x<<endl;
}
ll s[200005];
ll pre[200005];
int main()
{
	read(n);
	read(xx);
	for(int i=1;i<=n;i++)
	{
		read(s[i]);
		pre[i]=pre[i-1]+s[i];
	}
	ll ans=pre[n]*5+n*xx;
	for(int k=1;k<=n;k++)
	{
		ll res=0;
		for(int j=1,i=n;i>0;i-=k,j++)
		{
			ll rt=max(5,2*j+1);
			int las=max(0,i-k);
			res+=rt*(pre[i]-pre[las]);
		}
		ans=min(ans,res+k*xx);
	}
	out(ans+n*xx);
	return 0;
}