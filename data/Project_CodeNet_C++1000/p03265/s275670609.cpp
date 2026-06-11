#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    int x = c - a, y = d - b;
    printf("%d %d %d %d\n", c - y, d + x, a - y, b + x);
    return 0;
}