#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int i,a,b,c,k,maxn=-1;
	cin>>a>>b>>c>>k;
	for(i=1;i<=k;i++)
	{
		if(a>b&&a>c)
			a*=2;
		else if(b>a&&b>c)
			b*=2;
		else 
			c*=2;
	}
	cout<<a+b+c;
	return 0;
}