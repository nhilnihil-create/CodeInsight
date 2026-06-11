#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(abs(b - a) <= d && abs(b - c) <= d || abs(c - a) <= d) printf("Yes\n");
    else printf("No\n");
    return 0;
}