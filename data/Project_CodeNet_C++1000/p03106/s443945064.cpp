#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
typedef long long int LL;
using namespace std;
int main()
{
    LL A,B,K,cnt=0,n;
    scanf("%lld%lld%lld",&A,&B,&K);
    n=max(A,B);
    for(LL i=n;i>=1;i--)
    {
        if(A%i==0&&B%i==0)
            cnt+=1;
        if(cnt==K)
        {
            printf("%lld\n",i);
            return 0;
        }
    }
}