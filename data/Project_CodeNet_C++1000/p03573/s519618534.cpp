#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if(a == b) printf("%d\n", c);
    if(b == c) printf("%d\n", a);
    if(a == c) printf("%d\n", b);
    return 0;
}