#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;

#define int long long

int q,x,y;

bool check(int a)
{
	int i=max(1ll,(a>>1)-2),r=min(a,(a>>1)+2);
	for(;i<=r;++i)
		if((x+i)*(x+a-i)>=x*y)
			return false;
	return true;
}

void test()
{
	x=1;y=4;
	cout<<check(1);
}

signed main()
{
	//test();return 0;
	for(scanf("%lld",&q);q--;)
	{
		scanf("%lld%lld",&x,&y);
		if(x>y)
			swap(x,y);
		int left=0,mid,right=y-x,res=0;
		while(left<=right)
		{
			if(check(mid=(left+right)>>1))
				left=(res=mid)+1;
			else
				right=mid-1;
		}
		printf("%lld\n",((x-1)<<1)+res);
	}
	return 0;
}
