#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL a,b,c;

int main()
{
	scanf("%lld %lld %lld",&a,&b,&c);
	
	printf("%lld\n",b+min(a+b+1,c));
}