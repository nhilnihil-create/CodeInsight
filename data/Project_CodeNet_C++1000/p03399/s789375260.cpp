#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int ans = 0;
    if(a < b) ans = a;
    else ans = b;
    if(c < d) ans += c;
    else ans += d;
    printf("%d\n", ans);
    return 0;
}