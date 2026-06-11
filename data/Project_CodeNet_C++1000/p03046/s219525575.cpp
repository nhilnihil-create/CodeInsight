#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll m, k;

int main()
{
    cin>>m>>k;
    if((1 << m) <= k || m == 1 && k == 1)
    {
        printf("-1\n");
        return 0;
    }
    if(m == 1 && k == 0)
    {
        printf("0 0 1 1\n");
        return 0;
    }
    for(ll i = 0; i < (1 << m); i++)
    {
        if(i == k) continue;
        printf("%lld ", i);
    }
    printf("%lld ", k);
    for(ll i = (1 << m) - 1; i >= 0; i--)
    {
        if(i == k) continue;
        printf("%lld ", i);
    }
    printf("%lld", k);
    return 0;
}
