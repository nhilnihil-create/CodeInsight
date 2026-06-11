#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX_N 100
#define MAX_T 40000

int t[MAX_N];
double v[MAX_N], f[MAX_T];

double min(double a, double b)
{
    return a < b? a: b;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i]);
    for (int i = 0; i < n; i++)
        scanf("%lf", &v[i]);
    for (int i = 0; i < MAX_T; i++)
        f[i] = 1.E8;
    int tot = 0;
    for (int i = 0; i < n; i++) {
        t[i] *= 2;
        for (int j = tot; j <= tot + t[i]; j++)
            f[j] = min(f[j], v[i]);
        tot += t[i];
    }
    f[0] = f[tot] = 0.;
    for (int i = 1; i <= tot; i++)
        f[i] = min(f[i], f[i - 1] + .5);
    for (int i = tot - 1; i >= 0; i--)
        f[i] = min(f[i], f[i + 1] + .5);
    double ans = 0.;
    for (int i = 0; i < tot; i++)
        ans += .25 * (f[i] + f[i + 1]);
    printf("%.15f\n", ans);
    system("pause");
    return 0;
}