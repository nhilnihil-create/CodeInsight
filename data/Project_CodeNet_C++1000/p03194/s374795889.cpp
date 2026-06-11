#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <deque>
#include <algorithm>
#include <time.h>

using namespace std;
long long n,m,x,y,ans,cnt;
long long qpow(long long xx,long long yy)
{
	long long k=1;
	while(yy!=0)
	{
		if(yy&1!=0)
			k=k*xx;
		xx=xx*xx;
		yy=yy>>1;
	}
	return k;
}
int main()
{
	scanf("%lld%lld",&n,&m);
	if(n==1)
	{
		printf("%lld",m);
		return 0;
	}
	x=m;
	ans=1;
	for(int i=2;i<=sqrt(x);i++)
	{
		cnt=0;
		while(x%i==0)
		{
			x/=i;
			cnt++;
		}
		y=cnt/n;
		if(y)
			ans=ans*pow(i,y);
	}
	printf("%lld",ans);
	return 0;
}