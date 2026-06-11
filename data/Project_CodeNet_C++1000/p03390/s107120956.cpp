#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long ll;

ll T;
ll a, b;

int main()
{
    scanf("%lld", &T);
    while(T--)
    {
        scanf("%lld%lld", &a, &b);
        ll x = sqrt((double)a * b);
        if(a * b < x * x) x--;
        if(a * b == x * x)
        {
            printf("%lld\n", 2 * x - 3 + (a == b));
        }
        else
        {
            printf("%lld\n", 2 * x - (a * b <= x * (x + 1)) - 1);
        }
    }
    return 0;
}
