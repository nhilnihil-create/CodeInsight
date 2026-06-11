#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    bool f = abs(a-c)<=d;
    bool g = abs(a-b)<=d && abs(b-c)<=d;
    bool h = f || g;

    if (h) 
        printf("Yes");
    else 
        printf("No");

    return 0;
}