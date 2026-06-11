#include <cstdio>
#include <cstring>
#define FOR(i, l, r) for(int i = l; i <= r; ++i)

using namespace std;

const int T = 8010;

int n, ss[2], f[2][2][2 * T + 10], fl, now;
char s[T];

int main()
{
    scanf("%s", s + 1);
    n = strlen(s + 1); s[n + 1] = 'T';
    scanf("%d%d", &ss[0], &ss[1]);
    f[0][0][T] = f[1][0][T] = 1;
    FOR(j, 1, n + 1) if (s[j] == 'F') ++now;
    else
    {
        if (now == j - 1) f[0][0][T] = 0, f[0][0][T + now] = 1; else
        {
            FOR(i, 1, 2 * T)
                if (i - now > 0 && i + now <= 2 * T) f[fl][1][i] = f[fl][0][i - now] | f[fl][0][i + now]; else
                    f[fl][1][i] = i - now > 0 ? f[fl][0][i - now] : f[fl][0][i + now];
            FOR(i, 1, 2 * T) f[fl][0][i] = f[fl][1][i], f[fl][1][i] = 0;
        }
        fl ^= 1; now = 0;
    }
    if (f[0][0][ss[0] + T] && f[1][0][ss[1] + T]) puts("Yes"); else puts("No");
    return 0;
}
