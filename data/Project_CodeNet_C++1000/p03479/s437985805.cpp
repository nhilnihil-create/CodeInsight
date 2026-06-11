#include<stdio.h>
using namespace std;
int main(){
    long long x,y,srx,sum=0;
    scanf("%lld%lld",&x,&y);
    srx=((long long)(y/x));
    while(srx>=1)
    {srx/=2;
    sum++;}
    printf("%d\n",sum);
    return 0;
}