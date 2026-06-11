#include <bits/stdc++.h>
#define BIT(x) (1ll<<(x))
#define KMAX 35

using namespace std;
typedef long long llong;
struct Coord
{
    llong x, y;
} v[1005];

int n;

int main()
{
    scanf("%d", &n);
    scanf("%lld%lld", &v[0].x, &v[0].y);
    int par = ((v[0].x + v[0].y) % 2) == 0;
    int ok = 1;
    for(int i = 1; i < n; i++)
    {
        scanf("%lld%lld", &v[i].x, &v[i].y);
        int par2 = ((v[i].x + v[i].y) % 2) == 0;
        if(par != par2)
        {
            ok = 0;
            break;
        }
    }
    if(ok == 0)
        printf("-1");
    else
    {
        if(par)
            printf("%d\n1 ", KMAX + 1);
        else printf("%d\n", KMAX);
        for(int i = KMAX - 1; i >= 0; i--)
            printf("%lld ", BIT(i));
        printf("\n");
        for(int i = 0; i < n; i++)
        {
            llong x = v[i].x;
            llong y = v[i].y;
            if(par)
            {
                x--;
                printf("R");
            }
            llong ax, ay;
            for(int i = KMAX - 1; i >= 0; i--)
            {
                ax = abs(x);
                ay = abs(y);
                if(ax > ay)
                {
                    if(x < 0)
                    {
                        x += BIT(i);
                        printf("L");
                    }
                    else
                    {
                        x -= BIT(i);
                        printf("R");
                    }
                }
                else
                {
                    if(y < 0)
                    {
                        y += BIT(i);
                        printf("D");
                    }
                    else
                    {
                        y -= BIT(i);
                        printf("U");
                    }
                }
            }
            printf("\n");
        }
    }
    return 0;
}
