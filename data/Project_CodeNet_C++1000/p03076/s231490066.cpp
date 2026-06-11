#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 100005

#define PI 3.14159265358979323846264338327950

#define ll signed long long int
int main()
{
	int a,b,c,d,e,k=0,s,a1,b1,c1,d1,e1,z[5];
	cin>>a>>b>>c>>d>>e;
	if (a%10==0)
	k=k+a;
	else
	{
		a1=a%10;
		a=a/10;
		a=(a+1)*10;
		k=k+a;
	}
	if (b%10==0)
	k=k+b;
	else
	{
		b1=b%10;
		b=b/10;
		b=(b+1)*10;
		k=k+b;
	}
	if (c%10==0)
	k=k+c;
	else
	{
		c1=c%10;
		c=c/10;
		c=(c+1)*10;
		k=k+c;
	}
	if (d%10==0)
	k=k+d;
	else
	{
		d1=d%10;
		d=d/10;
		d=(d+1)*10;
		k=k+d;
	}
	if (e%10==0)
	k=k+e;
	else
	{
		e1=e%10;
		e=e/10;
		e=(e+1)*10;
		k=k+e;
	}
	if (a1!=0)
	z[0]=a1;
	else
	z[0]=10;
	if (b1!=0)
	z[1]=b1;
	else
	z[1]=10;
	if (c1!=0)
	z[2]=c1;
	else
	z[2]=10;
	if (d1!=0)
	z[3]=d1;
	else
	z[3]=10;
	if (e1!=0)
	z[4]=e1;
	else
	z[4]=10;
	sort(z,z+5);
	s=z[0];
	cout<<k-10+s;
}