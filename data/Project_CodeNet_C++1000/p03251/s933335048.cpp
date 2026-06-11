#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    rep(i, n)
    {
        int xi;
        cin >> xi;
        x = max(x, xi);
    }
    rep(i, m)
    {
        int yi;
        cin >> yi;
        y = min(y, yi);
    }

    for (int z = -100; z <= 100; ++z)
    {
        if (x < z && z <= y)
        {
            printf("No War\n");
            return 0;
        }
    }
    printf("War\n");
    return 0;
}