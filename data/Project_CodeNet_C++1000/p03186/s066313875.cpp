#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <iomanip>
using namespace std;
#define ll long long
 
inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=x*10+c-48;c=getchar();}
	return x*f;
}
 
inline ll llread()
{
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-') f=-1;c=getchar();}
	while(c<='9'&&c>='0'){x=x*10+c-48;c=getchar();}
	return x*f;
}

ll a,b,c;

int main()
{	
	a=llread(),b=llread(),c=llread();
	if(a+b+1>=c)
		printf("%lld\n",b+c);
	else
		printf("%lld\n",2*b+a+1);
	return 0;
} 