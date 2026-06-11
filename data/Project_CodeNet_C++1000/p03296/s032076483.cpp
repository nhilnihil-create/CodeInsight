#include <bits/stdc++.h>
using namespace std;
const int N = 1e2+5;
int n, a[N], ans;
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i) scanf("%d", a+i);
    for(int i = 1, c = 0; i <= n+1; ++i)
        if(a[i] != a[i-1]) ans += c/2, c = 1; else ++c;
    printf("%d\n", ans);
    return 0;
}