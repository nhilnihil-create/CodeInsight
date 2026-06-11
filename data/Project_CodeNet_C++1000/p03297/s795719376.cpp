#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	int t;
	scanf("%i",&t);
	while(t--)
	{
		ll a,b,c,d;
		scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
		if(a<b || b>d) printf("No\n");
		else
		{
			ll g=__gcd(b,d);
			ll tmp=c-b+1;
			ll o=a%g;
			ll t=(tmp%g+g)%g;
			ll add=(o-t+g)%g;
			if(tmp+add>=0) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}