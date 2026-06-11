#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll counts(ll s)//sum of the digits of s
{
	if(s == 0)
	{
		return 0;
	}
	return s % 10 + counts(s / 10);
}
ll nxt(ll x,ll y)//ceil(x/y)
{
	return (x + y - 1) / y;
}
int main()
{
	ll K;
	cin>>K;
	ll cur = 2,p = 1;
	while(K)
	{
		ll n = cur * p - 1;
		ll m = ceil((double)cur/10.0) * p * 10 - 1;
		if(n * counts(m) > m * counts(n))
		{
			cur = ceil((double)cur/10.0);
			p *= 10;
		}
		else
		{
			cout<<n<<endl;
			K--;
			cur++;
		}
		// printf("cur = %lld,p = %lld\n",cur,p);
	}
	return 0;
}