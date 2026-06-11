#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	long long i,j;
	scanf("%lld%lld",&i,&j);
	if(i>1)
		i-=2;
	if(j>1)
		j-=2;
	printf("%lld",i*j);
	return 0;
} 