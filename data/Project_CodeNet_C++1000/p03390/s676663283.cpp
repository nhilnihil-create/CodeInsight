#include<cstdio>
#include<iostream>
#include<algorithm>
#include<ctime>
#include<cstdlib>
#include<sys/time.h>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
inline int ri()
{
	register int x=0;register bool f=0;register char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();};
	return f?-x:x;
}
void wi(int x)
{
	if(x<0)	x=-x,putchar('-');
	if(x>9)	wi(x/10);
	putchar('0'+x%10);
}

int main()
{
	ll n=ri();
	while(n--)
	{
		ll a=ri(),b=ri();
		if(a==1&&b==1)
		{	
			wi(0);putchar('\n');
			continue;
		}
		if(a>b)	swap(a,b);
		ll s=a*b;	
		ll gg=sqrt((long double)(s-1));
		ll sum=gg*2;
		if(gg==(s-1)/gg)	sum--;
		if(a<=gg)	sum--;
		wi(sum);putchar('\n');
	}
	return 0;
}
