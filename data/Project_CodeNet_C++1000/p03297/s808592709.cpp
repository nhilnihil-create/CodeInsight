#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int T;
	scanf("%d", &T);
	while(T--)
	{
		ll a, b, c, d;
		scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
		if(a < b || d < b) { puts("No"); continue;}
		if(c >= b - 1) { puts("Yes"); continue;}
		a %= b;
		if(a > c) { puts("No"); continue;}
		d %= b;
		ll g = __gcd(b, d);
		if((b - 1) / g - c / g > 0) puts("No");
		else puts("Yes");
	}
	return 0;
}
		 
		