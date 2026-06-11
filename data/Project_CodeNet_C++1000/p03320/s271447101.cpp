#include<bits/stdc++.h>
#define ll long long
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return x*f;
}
ll D[18],d,now=1;
ll get_now(ll p){ll r=0;for(;p;r+=p%10,p/=10);return r;}
int main()
{
	D[0]=1;
	for(int i=1;i<=17;++i) D[i]=D[i-1]*10ll;
	int n=read();
	while(n--)
	{
		printf("%lld\n",now);
		if((now+D[d])*get_now(now+2*D[d])>(now+D[d]*2)*get_now(now+D[d])) d++;
		now+=D[d];
	}
	return 0;
}