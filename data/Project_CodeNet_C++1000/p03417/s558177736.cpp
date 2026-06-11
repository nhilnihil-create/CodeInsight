#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 1e2 + 5;

int main()
{
    ll n, m;
    scanf("%lld %lld", &n, &m);
    if(n == 1 && m == 1)
        printf("1\n");
    else if(min(n, m) == 2)
        printf("0\n");
    else if(min(n, m) == 1)
        printf("%d\n", max(n, m)-2);
    else
        printf("%lld\n", (n-2)*(m-2));
    return 0;
}
/****


****/
