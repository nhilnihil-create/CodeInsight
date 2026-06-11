#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read()
{
	char s;
	ll k=0,base=1;
	while((s=getchar())!='-'&&s!=EOF&&!(isdigit(s)));
	if(s==EOF)exit(0);
	if(s=='-')base=-1,s=getchar();
	while(isdigit(s)){k=k*10+(s^'0');s=getchar();}
	return k*base;
}
ll find(ll x,ll y)
{
	if (y>=x) return y+1; else return y;
}
ll q,x,y;
bool check(ll s)
{
	ll d=s/2;
	for (ll i=d-200;i<=d+200;i++)
	{
		if (i>0&&i<=s)
		{
			if (find(x,i)*find(y,s-i+1)>=x*y) return 0;
		}
	} 
	return 1;
} 
int main()
{
	q=read();
	while (q--)
	{
		x=read();y=read();
		ll l=0,r=2e9,ans=0;
		while(l<r)
		{
			ll mid=(l+r+1)/2;
			if (check(mid)) l=mid; else r=mid-1;
		}
		printf("%lld\n",l);
	}
	return 0;
}