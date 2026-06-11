#include <cstdio>
#include <cmath>

using namespace std;

long long a, b, c;
int q;

int main()
{
    scanf("%d", &q);
    while (q--)
    {
        scanf("%lld%lld", &a, &b);
        if (a == b) printf("%lld\n", 2 * a - 2);
        else
        {
            c = sqrt(a * b);
            if (c * c == a * b) --c;
            if (c * (c + 1) >= a * b) printf("%lld\n", 2 * c - 2);
                else printf("%lld\n", 2 * c - 1);
        }
    }
    return 0;
}
