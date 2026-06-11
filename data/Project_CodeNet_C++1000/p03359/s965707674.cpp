#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    int ans;
    if (a <= b)
        ans = a;
    else 
        ans = a - 1;

    printf("%d", ans);
    return 0;
}