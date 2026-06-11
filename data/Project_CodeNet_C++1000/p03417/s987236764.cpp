#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
	long long n,m;
	long long a;
	while(~scanf("%lld %lld",&n,&m))
	{
		a=abs((n-2)*(m-2));
	printf("%lld\n",a);
	}
	
	return 0;
 } 