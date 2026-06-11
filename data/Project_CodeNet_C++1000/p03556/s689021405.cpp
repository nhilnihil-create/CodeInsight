#include <cstdio>
#include <cmath>

int main()
{
    int n;
    scanf("%d", &n);

    int ans = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        ans = i*i;
    }

    printf("%d\n", ans);

    return 0;
}
