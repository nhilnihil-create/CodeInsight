#include <bits/stdc++.h>
#define FAST_IO ios::sync_with_stdio(false);cin.tie(0)

using namespace std;

int main()
{
    FAST_IO;

    int a, b, t;
    scanf("%d %d %d", &a, &b, &t);
    printf("%d\n", (t/a) * b);
    return 0;
}