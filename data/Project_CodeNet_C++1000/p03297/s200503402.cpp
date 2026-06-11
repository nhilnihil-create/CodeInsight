//Love and Freedom.
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
#define inf 20021225
using namespace std;
ll a,b,c,d;
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
bool okay(ll a,ll b,ll c,ll d)
{
	ll g=gcd(d,b); ll x=(b-a)/g*g;
	if((x+a)%b>c)	return 0;
	x=(b-a-1)/g*g;
	if((x+a)%b>c)	return 0;
	return 1; 
}
int main()
{
	int t; scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if(a<b || b>d){printf("No\n"); continue;}	a%=b;
		if(okay(a,b,c,d))	printf("Yes\n");
		else	printf("No\n");
	}
	return 0;
}
