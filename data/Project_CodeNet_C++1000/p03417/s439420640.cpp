#include<stdio.h>
#include<math.h>
#include<string.h>
#include<algorithm>
using namespace std;
int main()
{
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long sum=abs(a*b-a*2-b*2+4);
        printf("%lld\n",sum);
    return 0;
}