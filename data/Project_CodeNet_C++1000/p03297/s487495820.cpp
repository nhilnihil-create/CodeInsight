#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,c,d;
int main()
{
	int T;scanf("%d",&T);
	while (T--)
	{
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		if (a<b) puts("No");
		else if (a%b>c) puts("No");
		else if (d<b) puts("No");
		else if (b<=c) puts("Yes");
		else{
			ll Gcd=__gcd(b,d);
			if ((a-c-1)/Gcd-(a-b)/Gcd>0) puts("No");else puts("Yes");
		}
	}
	return 0;
}