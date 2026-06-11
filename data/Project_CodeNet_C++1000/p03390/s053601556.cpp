#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
long long A,B,AB;
bool check(long long l,long long r,long long mid)
{
	long long x=l,y=mid-l+1;
	for (int i=30; i>=0; i--)
		if (x+(1<<i)<=y-(1<<i)) x+=(1<<i),y-=(1<<i);
	if (x>=A) x++;
	if (y>=B) y++;
	return x*y<AB;
}
int main()
{
	int q;
	scanf("%d",&q);
	while (q--)
	{
		scanf("%lld%lld",&A,&B);
		if (A>B) swap(A,B);
		AB=A*B;
		long long l=0,r=(A+B)*2;
		while (l<r)
		{
			long long mid=(l+r+1)>>1;
			long long a=A,b=mid-B+1;
			bool flag=0;
			if(a>b) swap(a,b);
			if (mid<a) flag=check(1,mid,mid);
			else if(mid<b) flag=check(1,a-1,mid)&&check(a,mid,mid);
			else flag=check(1,a-1,mid)&&check(a,b-1,mid)&&check(b,mid,mid);
			if (flag) l=mid;
			else r=mid-1;
		}
		printf("%lld\n",l);
	}
	return 0;
}
