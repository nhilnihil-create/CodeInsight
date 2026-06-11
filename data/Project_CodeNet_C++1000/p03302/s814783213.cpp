#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
#define ll long long
#define out(a) printf("%d",a)
#define max a>b?a:b
#define min a<b?a:b
#define writeln printf("\n")
using namespace std;
int a,b;
int read()
{
	int s=0,t=1; char c;
	while (c<'0'||c>'9'){if (c=='-') t=-1; c=getchar();}
	while (c>='0'&&c<='9'){s=s*10+c-'0'; c=getchar();}
	return s*t;
}
ll readl()
{
	ll s=0,t=1; char c;
	while (c<'0'||c>'9'){if (c=='-') t=-1; c=getchar();}
	while (c>='0'&&c<='9'){s=s*10+c-'0'; c=getchar();}
	return s*t;
}
int main()
{
	a=read(); b=read();
	if (a+b==15) cout<<'+';
	else if (a*b==15) cout<<'*';
	else cout<<'x';
	return 0;
}