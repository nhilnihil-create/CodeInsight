#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int ans = 1;
    rep(i, n)
    {
        if(ans * 2 - ans < k) ans *= 2;
        else ans += k;
    }
    printf("%d\n", ans);
    return 0;
}