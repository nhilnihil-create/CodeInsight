#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read()
{
	ll out=0,fh=1;
	char jp=getchar();
	while ((jp>'9'||jp<'0')&&jp!='-')
		jp=getchar();
	if (jp=='-')
		{
			fh=-1;
			jp=getchar();
		}
	while (jp>='0'&&jp<='9')
		{
			out=out*10+jp-'0';
			jp=getchar();
		}
	return out*fh;
}
ll gcd(ll a,ll b)
{
	return a%b==0?b:gcd(b,a%b);
}
ll solve(ll a,ll b,ll m)//the smallest x where x>=a,x%m=b
{
	if((a%m+m)%m>b)
		b+=m;
    return a+b-(a%m+m)%m;
}
int judge(ll a,ll b,ll c,ll d)
{
	if(b>a || b>d)
		return 0;
	ll GCD=gcd(b,d);
	return solve(c-b+1,a%GCD,GCD)>=0;
}
int main()
{
	int T=read();
	while(T--)
		{
			ll a=read(),b=read(),c=read(),d=read();
			if(judge(a,b,c,d))
				puts("Yes");
			else
				puts("No");
		}
	return 0;
}