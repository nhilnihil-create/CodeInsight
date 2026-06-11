#include<stdio.h>
int main()
{
	long long m,n,k;
    scanf("%lld%lld",&m,&n);
    k=m*n-2*m-2*n+4;
    printf("%lld\n",k>0?k:-k);
}