#include <cstdio>
#define FOR(i, l, r) for(int i = l; i <= r; ++i)

using namespace std;

long long n, a, b;

int main()
{
    scanf("%lld%lld%lld", &n, &a, &b);
    if (a * b < n || a + b - 1 > n) {puts("-1"); return 0;}
    FOR(i, 1, a) if (n - i * b + i < a)
    {
        for(int j = n - a + i; j > (i - 1) * b; --j) printf("%d ", j);
        FOR(j, n - a + i + 1, n) printf("%d ", j);
        break;
    }
    else for(int j = i * b; j > (i - 1) * b; --j) printf("%d ", j);
    return 0;
}
