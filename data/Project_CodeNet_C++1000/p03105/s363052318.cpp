#include<bits/stdc++.h>
#define ll long long
inline int read()
{
	int x=0,y=1;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')
		y=-1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*y;
}
using namespace std;
int main()
{
	int a,b,c,d;
	a=read();
	b=read();
	c=read();
	d=b/a;
	c=min(c,d);
	printf("%d",c);
}