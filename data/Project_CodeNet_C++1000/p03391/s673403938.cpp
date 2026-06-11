#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n, a, b;
ll mn = 4e18;
ll sum;
bool v = false;

int main()
{
    scanf("%lld", &n);
    while(n--)
    {
        scanf("%lld%lld", &a, &b);
        sum += a;
        if(a > b)
        {
            v = true;
            mn = min(mn, b);
        }
    }
    printf("%lld\n", (sum - mn) * v);
    return 0;
}
