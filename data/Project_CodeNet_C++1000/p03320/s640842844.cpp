#include<bits/stdc++.h>
using namespace std;
long long n,x;
long long calc(long long x)
{
	long long s=0;
	while(x)
	{
		x/=10;
		s++;
	}
	return s;
}
double cal(long long x)
{
	long long s1=0,a1=x;
	while(x>0)
	{
		s1+=x%10;
		x/=10; 
	}
	return a1*1.0/s1;
}
long long pd(long long x)
{
	for(long long i=0;i<=calc(x);i++)if(cal(x+(long long)(pow(10,i)))<cal(x))return 0;
	return 1;
}
int main()
{
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=0;j<=calc(x);j++)
		if(pd(x+(long long)(pow(10,j))))
		{
			x=x+(long long)(pow(10,j));
			break;
		}
		cout<<x<<endl;
	}
	return 0;
} 