#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
    int a[3];
    rep(i, 3) scanf("%d", &a[i]);
    sort(a, a + 3);
    printf("%d\n", a[1] - a[0] + a[2] - a[1]);
    return 0;
}