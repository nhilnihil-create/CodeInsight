#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

ll n;
ll x, y;
ll ans;

int main()
{
    scanf("%lld", &n);
    x = -1;
    while(n--)
    {
        scanf("%lld", &y);
        if(x + 1 < y)
        {
            printf("-1\n");
            return 0;
        }
        else if(x + 1 == y) ans++;
        else ans += y;
        x = y;
    }
    printf("%lld\n", ans - 1);
    return 0;
}
