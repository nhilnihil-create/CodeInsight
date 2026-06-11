#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <vector>
#include <map>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <cassert>
#include <climits>
using namespace std;
typedef long long ll;
// #define DEBUG
#ifdef DEBUG
	#define debug printf
#else
	#define debug(...)
#endif
ll n,p;
const ll maxn = 1e12 + 5;
ll powme(ll k,ll s)
{
	if(s == 0ll)
	{
		return 1ll;
	}
	else if(s == 1ll)
	{
		return k;
	}
	ll t = powme(k,s / 2);
	if(t == -1)
	{
		debug("1::t = %lld\n",t);
		return -1;
	}
	// t *= t;
	if(t > p / t)
	{
		debug("2::t = %lld\n",t);
		return -1;
	} 
	t *= t;
	t *= powme(k,s % 2);
	debug("t = %lld\n",t);
	return t <= p ? t : -1ll;
}
int main(int argc, char const *argv[])
{
	cin>>n>>p;
	if(n == 1ll)
	{
		printf("%lld\n",p);
		return 0;
	}
	ll maxa = ll(pow(maxn,1.0 / (n + 0.0)));
	debug("maxa = %lld\n",maxa);
	for(ll i = maxa + 1;i >= 1; --i)
	{
		ll now = powme(i,n);
		debug("powme(%lld,%lld) = %lld\n",i,n,now);
		if(now <= p)
		{
			if(now > 0 && p % now == 0)
			{
				printf("%lld\n",i);
				return 0;
			}
		}
	}
	return 0;
}