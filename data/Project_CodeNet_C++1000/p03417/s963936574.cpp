#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    if(a==1)
        printf("%lld\n",abs(b-2));
    else
    {
        long long sum;
        sum=a*b-a*2-b*2+4;
        printf("%lld\n",abs(sum));
    }
    return 0;
}