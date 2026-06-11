#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
const int inf = 1e9; //1(1倍)e(指数)9(10^9)
int main()
{
    int n, t, a;
    scanf("%d%d%d", &n, &t, &a);
    int d = inf;
    int ans = 0;
    rep(i, n)
    {
        int h;
        scanf("%d", &h);
        int temp = abs((t * 1000 - h * 6) - a * 1000);
        if (temp < d)
        {
            d = temp;
            ans = i + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}