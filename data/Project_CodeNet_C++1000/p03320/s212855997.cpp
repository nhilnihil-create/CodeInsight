#include <bits/stdc++.h>
 
using namespace std;

double get(long long x)
{
	long long lx = x, nowans = 0;
	while(x)
	{
		nowans += x % 10;
		x /= 10;
	}
	return 1. * lx / nowans;
}
 
int main()
{
	int K;
	scanf("%d", &K);
	long long now = 0, delta = 1;
	for(int i = 1; i <= K; i++)
	{
		if(get(now + delta) > get(now + delta * 10))delta *= 10;
		now += delta;
		printf("%lld\n", now);
	}
}