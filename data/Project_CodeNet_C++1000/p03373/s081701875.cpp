#include<bits/stdc++.h>
using namespace std;
long long a,b,c,x,y,mn;
int main()
{
	scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&x,&y);
	mn=min(a+b,2*c);
	if(y>x)
	{
		printf("%lld\n",(y-x)*min(b,2*c)+mn*x);
	}else
	{
		printf("%lld\n",(x-y)*min(a,2*c)+mn*y);
	}
}