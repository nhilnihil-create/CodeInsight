#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#define ll long long
using namespace std;
int main() 
{
ll n,m;
	scanf("%lld%lld",&n,&m);
ll c=abs((n-2)*(m-2));
printf("%lld\n",c);
	return 0;
}