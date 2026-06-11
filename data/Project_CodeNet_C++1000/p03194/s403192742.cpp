#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

const int maxn=1000005;
long long c[maxn];
long long p[maxn], m;
void divide(long long n)
{
    m = 0;
    for(int i = 2; i <= sqrt(n)*10; i++)
	{
        if(n % i == 0)
		{
            p[++m] = i, c[m] = 0;
            while(n % i == 0)
			{
                n /= i, c[m]++;
            }
        }
    }
    if(n > 1)
	{
        p[++m]=n, c[m] = 1;
    }
}

long long ans=1;

long long val,mmm;

long long qm(long long a,long long b)
{
	long long qwe=1;
	while(b)
	{
		if(b&1)
		qwe=qwe*a;
		a=a*a;
		b>>=1;
	}
	return qwe;
}

int main()
{
	scanf("%lld%lld",&mmm,&val);
	divide(val);
	for(int i=1;i<=m;i++)
	{
	    long long k=c[i]/mmm;
		if(k!=0)
		{
		   long long rbq=qm(p[i],k);
		   ans *= rbq;
		}
	}
	printf("%lld",ans);
}