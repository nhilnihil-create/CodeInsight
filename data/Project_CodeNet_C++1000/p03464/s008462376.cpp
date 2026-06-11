#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define N 100000+5
using namespace std;
int n;
ll a[N],l=2,r=2;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=n;i>0;i--)
	{
        if(l % a[i]) l /= a[i],l = l*a[i]+a[i];
        r = (r/a[i]+1)*a[i]-1;
    }
    if(l > r) printf("-1");
    else printf("%lld %lld",l,r);
    printf("\n");
    return 0;
}