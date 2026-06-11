#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

typedef long long LL;

int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    
    if(!k)
    {
        printf("%lld\n", (LL)n * n);
        return 0;
    }
    
    LL res = 0;
    for(int b = k + 1; b <= n; b ++)
    {
        res += n / b * (b - k);
        if(n % b >= k)  res += n % b - k + 1;
    }
    printf("%lld\n", res);
    return 0;
}