#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int n, d, x;
    scanf("%d %d %d", &n, &d, &x);
    int a[n];
    rep(i, n) scanf("%d", &a[i]);
    int ans = x;
    rep(i, n)
    {
        int temp = 1;
        temp += (d - 1) / a[i];
        ans += temp;
    }
    printf("%d\n", ans);
    return 0;
}