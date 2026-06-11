#include<cstdio>  
#include<cmath>  
#include<iostream>  
#include<cstring>  
#include<iostream>  
#include<cstdlib>  
#include<string> 
using namespace std;
const int m=100007;

long long x[m],v[m];
long long a[m],b[m];
int main()
{
	
	long long n,c;
	 scanf("%lld %lld", &n, &c);
	for (int i=1;i<=n;i++)
	 scanf("%lld %lld", &x[i], &v[i]);  
	
	for (long long i=1;i<=n;i++)
	    a[i]=a[i-1]+v[i]-(x[i]-x[i-1]);
	x[n+1]=c;
	for (long long i=n;i>=1;i--)
	    b[i]=b[i+1]+v[i]-(x[i+1]-x[i]);
	    
	for (long long i=2;i<=n;i++)
	    a[i]=max(a[i-1],a[i]);
	for (long long i=n-1;i>=1;i--)
	    b[i]=max(b[i],b[i+1]);
	long long ans=0;
	for (long long i=1;i<=n;i++)
	{
		ans=max(ans,a[i]-x[i]+b[i+1]);
		ans=max(ans,b[i]-(c-x[i])+a[i-1]);
		ans=max(ans,b[i]);
		ans=max(ans,a[i]);
	}
	 printf("%lld\n", ans);  
}