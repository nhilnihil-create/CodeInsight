#include <iostream>
#include<cstdio>
#include<cmath>
using namespace std;
typedef long long ll;
ll S(ll x)//sum of the digits of s
{
	int r=0;
	while(x)
		r+=x%10,x/=10;
	return r;
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
		if(n * S(m) > m * S(n))
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