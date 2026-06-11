#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int a, b, c, k;
    scanf("%d%d%d%d", &a, &b, &c, &k);
    int max_n = max({a, b, c});
    int max_nk = max_n;
    rep(i, k) max_nk *= 2;
    printf("%d\n", a + b + c - max_n + max_nk);
    return 0;
}